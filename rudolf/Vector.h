/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *  
 * File:   Vector.h
 * Author: Rudolf
 *
 * Created on 22. Mai 2017, 23:35
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

class Vector {
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(const Vector& orig);
        virtual ~Vector();
        
        std::vector<Vector> linear(const Vector& end, int steps); 
        void printCoord() const;
        
        void setCoord(double x, double y, double z);
        void setCoord(const Vector& orig);
        
        double getX() const;
        double getY() const;
        double getZ() const;
        
    private:
        double x,y,z;
};

#endif /* VECTOR_H */

