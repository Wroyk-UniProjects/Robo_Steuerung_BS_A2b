/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *  
 * File:   Vector.cpp
 * Author: Rudolf
 * 
 * Created on 22. Mai 2017, 23:35
 */

#include "Vector.h"

Vector::Vector() {
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Vector& orig) {
    this->x = orig.getX();
    this->y = orig.getY();
    this->z = orig.getZ();
}

Vector::~Vector() {
    
}

std::vector<Vector> Vector::linear(const Vector& end, int steps) {
    
    std::vector<Vector> v_V;
    
    double dX = (end.getX()-(this->x))/(steps-1);
    double dY = (end.getY()-(this->y))/(steps-1);
    double dZ = (end.getZ()-(this->z))/(steps-1);
    
    Vector v (this->x,this->y,this->z);
    v_V.push_back(v);
    
    for(int i = 0; i < steps-1; i++) {
        
        v.setCoord(v_V[i].getX()+dX, v_V[i].getY()+dY, v_V[i].getZ()+dZ);
        v_V.push_back(v);
    }
    
    return v_V;
}

void Vector::printCoord() const{
    std::cout << "x: " << x << "\n" << "y: " << y << "\n" << "z: " << z << std::endl;
}

void Vector::setCoord(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector::setCoord(const Vector& orig) {
    this->x = orig.x;
    this->y = orig.y;
    this->z = orig.z;
}

double Vector::getX() const{
    return this->x;
}

double Vector::getY() const{
    return this->y;
}

double Vector::getZ() const{
    return this->z;
}