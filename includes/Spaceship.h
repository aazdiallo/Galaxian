#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <iostream>


//////////////////////////////
////// Class Spaceship //////
////////////////////////////

class Spaceship
{
public:
  Spaceship(Surface * psurface, int speed = 1, int score = 0)
    : psurface_(psurface),
      speed_(speed), level_(1),
      score_(score),
      is_alive_(true),
      life_(3),
      back_(0)
  {
    spaceship_rect = spaceship_image.getRect();
    spaceship_rect.x = W / 2 - spaceship_rect.w / 2;
    spaceship_rect.y = H - spaceship_rect.h - MENU_HIGHT;
  }

  void draw()
  {
    if (alive())
      {
	psurface_->put_image(spaceship_image, spaceship_rect);
	// blit image at rect on surface
      }
  }
  void move_left()
  {
    if (alive())
      {
	if (spaceship_rect.x > 0)
	  {
	    spaceship_rect.x -= speed_;
	  }
      }
  }
  void move_right()
  {
    if (alive())
      {
	if (spaceship_rect.x < W - spaceship_rect.w)
	  {
	    spaceship_rect.x += speed_;
	  }
      }
  }
  void move_up()
  {
    if (alive())
      {
	if (spaceship_rect.y > 0)
	  {
	    spaceship_rect.y -= speed_;
	  }
      }
  }
  void move_down()
  {
    if (alive())
      {
	if (spaceship_rect.y < H - spaceship_rect.h - MENU_HIGHT)
	  {
	    spaceship_rect.y += speed_;
	  }
      }
  }
  void fire_laser(int x, int y, int w, int h, int r, int g, int b)
  {
    psurface_->put_rect(x, y, w, h, r, g, b);
  }

   void arr_life(int h, int w, int r, int b, int g)
  {
    //std::cout << "drawing life \n";
    switch (life_)
      {
      case 3:
	{
	  psurface_->put_rect(lx, ly, h, w, b, r, g);
	  psurface_->put_rect(lx +20, ly, h, w, b, r, g);
	  psurface_->put_rect(lx + 40, ly, h, w, b, r, g);
	}
	break;

      case 2:
	{
	  psurface_->put_rect(lx, ly, h, w, b, r, g);
	  psurface_->put_rect(lx +20, ly, h, w, b, r, g);
	}
	break;

      case 1:
	{
	  psurface_->put_rect(lx, ly, h, w, b, r, g);
	}
	break;
	
      }
  }

  int get_x()
  {
    return spaceship_rect.x;
  }
  
  int get_y()
  {
    return spaceship_rect.y;
  }
  
  int get_w()
  {
    return spaceship_rect.w;
  }
  
  int get_h()
  {
    return spaceship_rect.h;
  }
  
  void die()
  {
    is_alive_ = 0;
  }
  
  bool alive()
  {
    return is_alive_;
  } 
  
  void score(int x)
  {
    switch(x)
      {
      case 1: // When ship kills a green alien
	score_ += 20;
	break;

      case 2: // When ship kills a red alien
	score_ += 40;
	break;

      case 3: // When ship kills a yellow alien
	score_ += 80;
	break;
      }
    
    return;
  }

   int total_score()
  {
    return score_;
  }

  int level()
  {
    return level_;
  }

   void increase_level()
  {
    level_++;

    return;
  }

   int life()
  {
    return life_;
  }

   void decrease_life()
  {
    --life_;

    return;
  }

  void back_to_life()
  {
    // If the ship is dead and has remining lives
    if(life_ > 0 && !is_alive_)
      {
	back_to_life_delay();

	// If the ship is dead 800 iterations ago
	if(ready_to_live() > 800)
	  {
	    back_ = 0; // Reset death_delay to 0
	    spaceship_rect.x = W / 2 - spaceship_rect.w / 2;
	    spaceship_rect.y = H - spaceship_rect.h - MENU_HIGHT;
	    is_alive_ = 1; // Set the ship back to life 
	  }
      }
    return;
  }

  void back_to_life_delay()
  {
    back_++;

    return;
  }

  int ready_to_live()
  {
    return back_;
  }

  
private:  // Move to private when complete
  Surface * psurface_;
  static Image spaceship_image;
  static Image dead_;
  Rect spaceship_rect;
  bool is_alive_;
  int speed_;
  int score_;
  int level_;
  int life_;
  int back_;

  // life coordonates
  int lx = 550;
  int ly = H - 15;
  
};

Image Spaceship::spaceship_image("images/galaxian/GalaxianGalaxip.gif");
Image Spaceship::dead_("images/galaxian/explods.png");

#endif /* SPACESHIP_H */

