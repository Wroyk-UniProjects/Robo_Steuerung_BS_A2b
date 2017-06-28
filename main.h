/* 
 * File:   main.h
 * Author: Rudolf
 *
 * Created on 15. Juni 2017, 13:20
 */

#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include "rudolf/Vector.h"
#include "rudolf/Robot.h"
#include "vani/robo.h"
#include "vani/vektor.h"
#include"vani/coord.h"

int makeChilds(int n, pid_t *pid);
std::vector<MotorPos> runRB(double *s);
std::vector<MotorPos> runV(double *s);


#endif /* MAIN_H */

