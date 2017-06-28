/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *  
 * File:   MotorPos.cpp
 * Author: Rudolf
 *
 * Created on 23. Mai 2017, 11:36
 */

#include "MotorPos.h"

MotorPos::MotorPos(){
    this->a = 0;
    this->b = 0;
    this->c = 0;
}
MotorPos::MotorPos(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
}
MotorPos::MotorPos(const MotorPos& orig){
    this->a = orig.getA();
    this->b = orig.getB();
    this->c = orig.getC();
}
MotorPos::~MotorPos(){
}

void MotorPos::setA(double a){
   this->a = a; 
}
void MotorPos::setB(double b){
    this->b = b;
}
void MotorPos::setC(double c){
    this->c = c;
}

double MotorPos::getA() const{
    return this->a;
}
double MotorPos::getB() const{
    return this->b;
}
double MotorPos::getC() const{
    return this->c;
}

void MotorPos::printMoterPos() const{
    std::cout << "   a: "<< this->a << "\n" << "   b: " << this->b << "\n" << "   c: " << this->c << std::endl; 
}
