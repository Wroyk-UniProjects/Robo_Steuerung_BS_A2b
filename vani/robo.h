#ifndef ROBO_H
#define ROBO_H
#include <stdio.h>
#include <stdlib.h>
#include "coord.h"
#include <string>
#include <iostream>


class robo{

private: double x,y,z;

public:
         robo(double x, double y, double z);
         ~robo();
         robo(const coord&);
         robo(const robo&);
         robo& operator=(const robo&);
         double getX() const;
         double getY() const;
         double getZ() const;
         coord inverse(const coord&);
         void drive(const coord&) const;
};
//std::ostream& operator<<(std::ostream& ,const line&);


#endif
