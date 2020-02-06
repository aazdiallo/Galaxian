#ifndef LASER_H
#define LASER_H
#include <iostream>
#include "Surface.h"
#include "Spaceship.h"
#include "vec2d.h"
#include "Aliens.h"

///////////////////////////
/////// Laser Class //////
/////////////////////////

class Laser
{
public:
  Laser(Spaceship * pspaceship=NULL,
	double x=0.0, double y=0.0, double dy=-2.0, double dya = .5,
	int w=4, int h=10, int r=160, int g=4, int b=69, bool is_alive=0)
    : pspaceship_(pspaceship),
      p_(x, y),
      v_(0, dy),
      pv_(x, y),
      av_(0, dya),
      w_(w), h_(h),
      r_(r), g_(g), b_(b),
      is_alive_(is_alive)
  {}

  bool ready()
  {
    return !is_alive_;
  }
  
  void shoot() // Firing method, gets the coordinates of spaceship
  {
    is_alive_ = 1;
    p_[0] = pspaceship_->get_x() + pspaceship_->get_w() / 2 - 2;
    p_[1] = pspaceship_->get_y() - pspaceship_->get_h() / 2 + 1;

    return;
  }

  void run()
  {
    if (p_[1] + h_ < 0) // If laser is off screen
      is_alive_ = 0;
       
    if (p_[1] < H && is_alive_)
      p_ += v_;
    
    return;
  }

  ////////////////////////////
  //// spaceship methods ////
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
  
  void draw() // Drawing laser for spaceship
  {
    if (is_alive_)
      {
	if (p_[1] < H && p_[1] >= 0)
	  pspaceship_->fire_laser(p_[0], p_[1], w_, h_, r_, g_, b_);
      }
       
    return;
  }

  void draw_life() // Drawing life for spaceship
  {
    if (pspaceship_->life() > 0)
      {
	//std::cout << pspaceship_->life() << '\n';
	pspaceship_->arr_life (h_, w_, r_, b_, g_);
      }
       
    return;
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
  vec2d pv_; // position of aliens' laser
  vec2d av_; // Velocity of aliens' laser
  int w_;
  int h_;
  int r_;
  int g_;
  int b_;
  bool is_alive_;
  bool is_alive_a_;
  Spaceship * pspaceship_;
  Aliens * paliens_;
  
};

#endif /* LASER_H */

