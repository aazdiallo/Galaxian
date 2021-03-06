#ifndef ALASER_H
#define ALASER_H
#include <iostream>
#include "Surface.h"
#include "Spaceship.h"
#include "vec2d.h"

///////////////////////////
/////// ALaser Class //////
/////////////////////////

class ALaser
{
public:
  ALaser(Surface * psurface=NULL, //Aliens * palien=NULL,
	  double x=0.0, double y=0.0, double dy=0.5, int w=4, int h=10,
	  int r=160, int g=4, int b=69, bool is_alive=0)
    : psurface_(psurface),
      p_(x, y),
      v_(0, dy),
      w_(w), h_(h),
      r_(r), g_(g), b_(b),
      is_alive_(is_alive)
  {}

  bool ready()
  {
    return !is_alive_;
  }
  
  void shoot(int x, int y) // gets the coordinates of aliens
  {
    is_alive_ = 1;
    p_[0] = x;
    p_[1] = y;

    return;
  }

  void run()
  {
    if (p_[1] > H) // If laser is off screen
      is_alive_ = 0;
       
    if (p_[1] <= H && is_alive_)
      p_ += v_;
    
    return;
  }

  void draw() // Drawing laser for spaceship
  {
    if (is_alive_)
      {
	if (p_[1] <= H)
	  psurface_->put_rect(p_[0], p_[1], w_, h_, r_, g_, b_);
      }
    return;
  }

  int get_x()
  {
    return p_[0];
  }

  int get_y()
  {
    return p_[1];
  }
   int get_h()
  {
    return h_;
  }

  int get_w()
  {
    return w_;
  }
  
   bool alive()
  {
    return is_alive_;
  }

  void die()
  {
    is_alive_ = 0;
  }
        
private:
  vec2d p_;  // Position vector of star
  vec2d v_;  // Velocity vector of star
  int w_;
  int h_;
  int r_;
  int g_;
  int b_;
  bool is_alive_;
  Spaceship * pspaceship_;
  Surface * psurface_;
  
};

#endif /* ALASER_H */

