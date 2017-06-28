#ifndef VEKTOR_H
#define VEKTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "coord.h"


class vektor{

private: coord Start_coord;
         coord End_coord;

public:  vektor();
         ~vektor();
         vektor(const coord&, const coord&);
         vektor(const vektor&);
         vektor& operator=(const vektor&);
         coord getStart()const;
         coord getEnd()const;
         std::vector<coord> linear(const coord&, const coord&);

};
//std::ostream& operator<<(std::ostream&,const line&);



#endif // INVERSE_H
