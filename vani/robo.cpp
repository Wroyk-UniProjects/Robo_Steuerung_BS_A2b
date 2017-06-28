#include "robo.h"
#include "vektor.h"
#include <cmath>

robo::robo(double x, double y, double z)
{
    robo::x=x;
    robo::y=y;
    robo::z=z;
}
robo::~robo()
{

}

robo::robo(const coord& coord)
{
    robo::x=coord.getX();
    robo::y=coord.getY();
    robo::z=coord.getZ();
}
robo::robo(const robo& ro)
{
   robo::x=ro.getX();
   robo::y=ro.getY();
   robo::z=ro.getZ();
}
robo& robo::operator=(const robo& ro)
{
    robo::x=ro.getX();
    robo::y=ro.getY();
    robo::z=ro.getZ();

    return *this;
}

double robo::getX() const
{
    return x;
}

double robo::getY() const
{
   return y;
}

double robo::getZ() const
{
    return z;
}

 coord robo::inverse(const coord& c)
 {
     coord out(0,0,0);
     x = c.getX();
     y = c.getY();
     z = c.getZ();
     double radFi = 60.0* 3.141592653 / 180;
     
     out.setX(sqrt(pow(233.0,2)-pow(-x,2)-pow(147.0-y,2))+z);
     out.setY(sqrt(pow(233.0,2)-pow(-147.0*sin(radFi)-x,2)-pow(-147.0*cos(radFi)-y,2))+z);
     out.setZ(sqrt(pow(233.0,2)-pow(147.0*sin(radFi)-x,2)-pow(-147.0*cos(radFi)-y,2))+z);

    return out;
 }

void robo::drive(const coord& c) const
{
   std::cout << "(" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")" << std::endl;
}



