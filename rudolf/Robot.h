/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *  
 * File:   Robot.h
 * Author: Rudolf
 *
 * Created on 23. Mai 2017, 11:36
 */

#ifndef ROBOT_H
#define ROBOT_H

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include "MotorPos.h"
#include "Vector.h"

class Robot {
public:
    Robot();
    Robot(double l, double d, double fi);
    Robot(const Robot& orig);
    virtual ~Robot();
    
    MotorPos inverse(const Vector& v);
    std::vector<MotorPos> inverse(const std::vector<Vector>& v);
    
    void drive(const MotorPos& mP);
    void drive(const std::vector<MotorPos>& mP);
    
    double getL() const;
    double getD() const;
    double getFI() const;
private:
    double l,d,fi;

};

#endif /* ROBOT_H */

