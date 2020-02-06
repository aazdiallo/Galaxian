#ifndef VEC2D_H
#define VEC2D_H
#include <iostream>


///////////////////////////
/////// Vec2d Class //////
/////////////////////////


class vec2d
{
public:
    vec2d(double x, double y)
        : x_(x), y_(y)
        {}
        vec2d operator +=(const vec2d & v)
        {
            x_ += v.x_;
            y_ += v.y_;
            return (*this);
        }
        // read a value ... std::cout << v[0]
        double operator[](int i) const
        {
            if (i == 0)
            {return x_;}
            else
            {return y_;}
        }
        // v[0] = 5
        double & operator[](int i)
        {
            if (i == 0)
            {return x_;}
            else
            {return y_;}
        }

  vec2d operator-() const
  {
    vec2d s(x_ * -1, y_ * -1);
        
    return s;
  }
    double x_;
    double y_;
};


std::ostream & operator<<(std::ostream & cout, const vec2d & v)
{
    cout << '<' <<  v[0] << ", " << v[1] << '>';
    return cout;
}

#endif /* VEC2D_H */
