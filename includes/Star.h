#ifndef STAR_H
#define STAR_H
#include <iostream>
#include "vec2d.h"

/////////////////////////
////// STAR CLASS //////
///////////////////////

class Star
{
public:
    Star(Surface * psurface=NULL,
            double x=0.0, double y=0.0, double dy=1.0, int rad=3,
            int r=255, int g=255, int b=255)
          : psurface_(psurface),
            p_(x, y), //x_(x), y_(y),
            v_(0, dy), //dy_(dy),
            width_(rad),
            r_(r), g_(g), b_(b)
         { // Randomize the place of the stars in the space
                p_[1] = rand() % H;
                p_[0] = rand() % W;
                width_ = rand() % 3 + 1;
		
                if (width_ == 1)
                {
                    //slowest
		  r_ = rand() % 36 + 80;
		  g_ = rand() % 36 + 80;
		  b_ = rand() % 36 + 80;
                    v_[1] = 0.05;
                }
	       
                else if (width_ == 2)
                {
		  //slowest
		  r_ = rand() % 15 + 220;
		  g_ = rand() % 15 + 220;
		  b_ = rand() % 15 + 220;
                    v_[1] = 0.8;
                }
		
                else
                {
                    //fastest
                    r_ = rand() % 36 + 150;
                    g_ = rand() % 36 + 150;
                    b_ = rand() % 36 + 150;
                    v_[1] = 0.07;
                }
		
          }
         // simulate moving stars on the space
            void run() 
            {
                p_[1] += v_[1];
                // reset y and change x
                if (p_[1] - width_ > H)
                {
                    p_[1] = 0.0;
                    p_[0] = rand() % W;
                    width_ = rand() % 3 + 1;
                    if (p_[1] == 1)
                    {
                        //slowest
                        r_ = rand() % 15 + 80;
                        g_ = rand() % 15 + 80;
                        b_ = rand() % 15 + 80;
                        v_[1] = 0.5;
                    }
                    else if (p_[1] == 2)
                    {
                        //slowest
                        r_ = rand() % 15 + 220;
                        g_ = rand() % 15 + 220;
                        b_ = rand() % 15 + 220;
                        v_[1] = 0.8;
                    }
		    
                    else
                    {
		      //fastest
		      r_ = rand() % 36 + 150;
		      g_ = rand() % 36 + 150;
		      b_ = rand() % 36 + 150;
		      v_[1] = 1;
                    }
                }	
            }
            
            
            void draw()
            {
                psurface_->put_circle(int(p_[0]), int(p_[1]), width_,
                        r_, g_, b_);
            }
private:
  vec2d p_;  // Position vector of star
  vec2d v_;  // Velocity vector of star
  int width_;
  int r_;
  int g_;
  int b_;
  Surface * psurface_;
  
};


#endif /* STAR_H */
