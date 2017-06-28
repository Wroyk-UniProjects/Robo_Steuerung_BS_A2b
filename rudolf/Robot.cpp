/*
 * Betribssicherheit
 * Aufgabe 2 Teil a
 * Robotorsteuerung in C++
 *
 *  
 * File:   Robot.cpp
 * Author: Rudolf
 * 
 * Created on 23. Mai 2017, 11:36
 */

#include "Robot.h"

Robot::Robot() {
    this->l = 0.0;
    this->d = 0.0;
    this->fi = 0.0;
}

Robot::Robot(double l, double d, double fi) {
    this->l = l;
    this->d = d;
    this->fi = fi;
}

Robot::Robot(const Robot& orig) {
    this->d = orig.getD();
    this->l = orig.getL();
    this->fi = orig.getFI();
}

Robot::~Robot() {
}

 MotorPos Robot::inverse(const Vector& v) {
     MotorPos mP (0, 0, 0);
     
     double x = v.getX(), y = v.getY(), z = v.getZ();
     
     double radFi = this->fi * 3.141592653 / 180;
     
     double dSinXneg = -this->d * std::sin(radFi) - x;
     double dSinX = this->d * std::sin(radFi) - x;
     double dCosY = -this->d * std::cos(radFi) - y;
     
     mP.setA(std::sqrt(std::pow(l,2) - std::pow(x,2) - std::pow((this->d-y),2) ) + z);
     mP.setB(std::sqrt(std::pow(l,2) - std::pow(dSinXneg,2) - std::pow(dCosY,2) ) + z);
     mP.setC(std::sqrt(std::pow(l,2) - std::pow(dSinX,2) - std::pow(dCosY,2) ) + z);
     
     return mP;
 }
 
 std::vector<MotorPos> Robot::inverse(const std::vector<Vector>& v) {
     std::vector<MotorPos> mP;
     for(int i = 0; i < v.size(); i++) {
         mP.push_back(this->inverse(v[i]));
     }
     return mP;
 }
 
 void Robot::drive(const MotorPos& mP) {
     mP.printMoterPos();
 }
 void Robot::drive(const std::vector<MotorPos>& mP) {
     for(int i = 0; i < mP.size(); i++) {
         std::cout << "Position " << i+1 << std::endl;
         mP[i].printMoterPos();
     }
 }
 
double Robot::getL() const{
    return this->l;
}
double Robot::getD() const{
    return this->d;
}
double Robot::getFI() const{
    return this->fi;
}