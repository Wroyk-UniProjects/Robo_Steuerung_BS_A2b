#include "coord.h"

coord::coord()
{
    x=0;
    y=0;
    z=0;
}

coord::~coord()
{

}

coord::coord(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
coord::coord(const coord& co)
{
    x=co.getX();
    y=co.getY();
    z=co.getZ();
}



double coord::getX() const
{
    return x;
}
double coord::getY() const
{
    return y;
}
double coord::getZ() const
{
    return z;
}
void coord::setX(double x)
{
    this->x=x;
}
void coord::setY(double y)
{
    this->y=y;
}
void coord::setZ(double z)
{
    this->z=z;
}
