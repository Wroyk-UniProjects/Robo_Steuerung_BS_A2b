#include "robo.h"
#include "vektor.h"
#include <cmath>


vektor::vektor()
{
    Start_coord= coord(0,0,0);
    End_coord= coord(0,0,0);
}

vektor::vektor(const coord& a,const coord& e)
{
    Start_coord=a;
    End_coord=e;
}
vektor::~vektor(){
    
}
vektor::vektor(const vektor& vek)
{
    Start_coord=vek.getStart();
    End_coord=vek.getEnd();

}


vektor& vektor::operator=(const vektor& vek)
{
    Start_coord=vek.getStart();
    End_coord=vek.getEnd();

    return *this;
}

coord vektor::getStart()const
{
    return Start_coord;
}

coord vektor::getEnd()const
{
    return End_coord;
}

std::vector<coord> vektor::linear(const coord& c1, const coord& c2)
{
    robo r(0,0,0);
    coord c(0,0,0);
    std::vector<coord> out;
    std::vector<coord> in;
    Start_coord = c1;
    End_coord   = c2;
    
    double dX = (End_coord.getX()-(Start_coord.getX()))/(9);
    double dY = (End_coord.getY()-(Start_coord.getY()))/(9);
    double dZ = (End_coord.getZ()-(Start_coord.getZ()))/(9);
    
    in.push_back(Start_coord);
    for(int i = 0; i < 9; i++) {
        c.setX(in[i].getX()+dX);
        c.setY(in[i].getY()+dY);
        c.setZ(in[i].getZ()+dZ);
        in.push_back(c);
    }
    for(int i = 0; i < 10; i++){
        out.push_back(r.inverse(in[i]));
    }
     return out;
}




