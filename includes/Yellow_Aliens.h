#ifndef YELLOWALIENS_H
#define YELLOWALIENS_H
#include <iostream>
#include "vec2d.h"
#include "Spaceship.h"

//////////////////////////////
////// Class Yellow_Aliens //////
////////////////////////////

class YellowAliens
{
public:
  YellowAliens(Surface * psurface=NULL, Spaceship * space=NULL, ALaser ** alaser=NULL,
	       double x=0.0, double y=0.0, double dy=-2.0, int w=4, int h=10,
	       int r=160, int g=4, int b=69)
    : psurface_(psurface), pspace_(space), aliens_per_row(YELLOW_ALIENS),
      alaser_(alaser),
      is_alive_(true),
      w_(w), h_(h),
      r_(r), g_(g), b_(b),
      p_(0.0, 0.0),
      v_(.5, 0.0),
      f_p_(0.0, 0.0),
      f_v_(.5, 0.0),
      mode_(0)
  {
    row_ = (total_aliens) / (aliens_per_row);    
    total_aliens++;
    column_ = 1 + (3) * abs(total_aliens - 1);
    aliens_rect_ = yellow_alien_.getRect();
    aliens_rect_.y = p_[1]  = D_BTWN_TOP + SPACER + (aliens_rect_.h + SPACER) * row_;
    aliens_rect_.x = p_[0]  = SPACER + (aliens_rect_.w + SPACER) * column_;
    
  }

  void set_Coordinates()
  {
     aliens_rect_.x = p_[0];
     aliens_rect_.y = p_[1];
  }

  void draw()
  {
    if(alive())
    {
      set_Coordinates();
      psurface_->put_image(yellow_alien_, aliens_rect_); // put image on surface
    }
  }
 
  void attack_mode()
  {
    if (mode_ == 0)
      {
	int random = rand() % 5000;
	if (random == 0)
	  mode_ = 1;
      }
    
    else if (mode_ == 1)
      {
	mode_ = 2;
      }

    else
      {
	mode_ = 0;
      }
  }

  void fire_laser()
  {
    if(is_alive_)
      {
  	for (int i = 0; i < 4; i++)
  	  {
  	    if (alaser_[i]->ready())
  	      {
  		double laserx = get_x() + get_w()/2;
  		double lasery = get_y() + get_h() + 1;
  		alaser_[i]->shoot(laserx, lasery);
  		break;
  	      }
  	  }
      }
  }
  
  void run()
  {
    if (out_screen_original())
      {
	f_v_ = -f_v_;
      }
    
    f_p_ += f_v_;
	    
    if(alive())
      {
	if (mode_ == 0)
	  {
	    attack_mode();
	    f_p_[0] = p_[0];
	    f_p_[1] = p_[1];
	    
	    f_v_[0] = v_[0];
	    f_v_[1] = v_[1];
	    
	    if (out_screen())
	      v_ = -v_;
    
	    p_ += v_;

	    
	    bullet_speed++;
	  }
	
	if(mode_ == 1)
	  {
	    if(bullet_speed > 200)
	      fire_laser();
	    //bullet_speed = 0;
	    double amplitude = (p_[0] - pspace_->get_y()) / 300;
	    v_[0] = sin(p_[1]/45) * amplitude;
	    
	    v_[1] = .25; // Velocity speed of y
	    if (pspace_->get_x() > p_[0] && pspace_->alive() )
	      {
	    	p_[0] += .25;
	      }
	    else if(pspace_->get_x() < p_[0] && pspace_->alive())
	      {
		p_[0] += -.25;
	      }
	    
	    p_ += v_;
	    if(p_[1] > H)
	      {
		bullet_speed = 0;
		mode_ = 2;
		p_[1] = -200;
		p_[0] = f_p_[0];
	      }
	  }
	
	if(mode_ == 2)
	  {
	    if(f_p_[0] < p_[0] )
	      {
		p_[0] -= v_[0];
		p_[1] += v_[1];
	      }
	    
	    if(f_p_[0] > p_[0])
	      {
		p_[1] += v_[1];
	      }

	    if(p_[1] == f_p_[1])
	      {
		v_[1] = 0;
	      }

	    if(p_[0] == f_p_[0])
	      {
		v_[0] = 0;
	      }
	      
	    if (p_[0] == f_p_[0] && p_[1] == f_p_[1])
	      {
		p_[1] = f_p_[1];
	        v_[1] = f_v_[1];
		v_[0] = f_v_[0];
		
		mode_ = 0;
	      }
	  }
	
      }
    
    return;
  }
 
  // moving an alien downward

  bool out_screen()
  {
    return ((p_[0] + ((aliens_rect_.w + SPACER) *
		      (abs(column_ - aliens_per_row))))> W ||
	    (p_[0] - (column_ * (aliens_rect_.w + SPACER)) < 0 ));
  }

  
    bool out_screen_original()
  {
    return ((f_p_[0] + ((aliens_rect_.w + SPACER) *
		      (abs(column_ - aliens_per_row))))> W ||
	    (f_p_[0] - (column_ * (aliens_rect_.w + SPACER)) < 0 ));
  }
  
  int get_x()
  {
    return aliens_rect_.x;
  }
  
  int get_y()
  {
    return aliens_rect_.y;
  }
  
  int get_w()
  {
    return aliens_rect_.w;
  }
  
  int get_h()
  {
    return aliens_rect_.h;
  }

  void die()
  {
    is_alive_ = 0;
  }
  
  bool alive()
  {
    return is_alive_;
  } 

   // set alien to alive for next levels
  void back_to_life()
  {
    p_[0] = f_p_[0];
    p_[1] = f_p_[1];
    v_[0] = f_v_[0];
    v_[1] = f_v_[1];
    mode_ = 0;
    deadAliens = 0;
    is_alive_ = 1;
   
    return;
  }

  bool is_dead()
  {
    if(is_alive_ == 0)
      
    return true ;
  }

   void dead()
  {
    deadAliens++;

    return;
  }

  int deadNumber()
  {
    return deadAliens;
  }

  
private:  // Move to private when complete
  Surface * psurface_;
  Spaceship * pspace_;
  static Image yellow_alien_;
  Rect aliens_rect_;
  Rect dead_;
  bool is_alive_;
  vec2d p_;
  vec2d v_;
  vec2d f_p_;
  vec2d f_v_;
  int row_;
  int column_;
  static int total_aliens;
  int mode_;
  int aliens_per_row;
  ALaser ** alaser_;
  int bullet_speed = 0;
  int deadAliens = 0;
  
  //Laser attributes
  int w_;
  int h_;
  int r_;
  int g_;
  int b_;
  
  
};

int YellowAliens :: total_aliens = 0;
Image YellowAliens::yellow_alien_("images/galaxian/GalaxianYellow.gif");

#endif /* YELLOWALIENS_H */

