/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *
 * File:   MotorPos.h
 * Author: Rudolf
 *
 * Created on 23. Mai 2017, 11:36
 */

#ifndef MOTORPOS_H
#define MOTORPOS_H

#include <iostream>
#include <cstdlib>
class MotorPos {
    
public:
    MotorPos();
    MotorPos(double a, double b, double c);
    MotorPos(const MotorPos& orig);
    virtual ~MotorPos();
    
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getA() const;
    double getB() const;
    double getC() const;
    
    void printMoterPos() const;
    
private:
    double a,b,c;
};

#endif /* MOTORPOS_H */