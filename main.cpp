/*
 * Betribssicherheit
 * Aufgabe 2 Teil b
 * Robotorsteuerung in C++
 *
 *  
 * File:   main.cpp
 * Author: Rudolf u. Vanessa
 *
 * Created on 13. Juni 2017, 12:19
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <vector>
#include "main.h"


#define PCOUNT 2
#define COUNT 10

using namespace std;

int main(void) {
    
    pid_t pid[PCOUNT] = {-1,-1};
    
    int handle1 = shm_open("/shm1", O_CREAT | O_RDWR, 0777);
    ftruncate(handle1,2048*sizeof(double));
    char *memory1 = (char *)mmap(0, 2048*sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED, handle1, 0);
    double *motorPos1 = (double*)memory1;
    
    int handle2 = shm_open("/shm2", O_CREAT | O_RDWR, 0777);
    ftruncate(handle2,2048*sizeof(double));
    char *memory2 = (char *)mmap(0, 2048*sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED, handle2, 0);
    double *motorPos2 = (double*)memory2;
    
    switch( makeChilds(PCOUNT, pid) ){
        case -1:
            cout << "faile" << endl;
            break;
        case 0:
            if(pid[0] == 0){
                runR(motorPos1);
            }
            if(pid[1] == 0){
                runV(motorPos2);
            }
            return 0;
        default:
            
            int status;
            waitpid(pid[0], &status, 0);
            waitpid(pid[1], &status, 0);
            
            std::vector<MotorPos> motorPos;
            MotorPos m(0,0,0);
            Robot robot (0, 0 ,0);
            
            bool b[COUNT];
            int j =0;
            for(int i=0; i<COUNT; i++){
                if(motorPos1[j]==motorPos2[j]){
                    m.setA(motorPos1[j]);
                    //cout << "war" << endl;
                }
                if(motorPos1[j+1]==motorPos2[j+1]){
                    m.setB(motorPos1[j+1]);
                    //cout << "war" << endl;

                }
                if(motorPos1[j+2]==motorPos2[j+2]){
                    m.setC(motorPos1[j+2]);
                    //cout << "war" << endl;

                }
                b[i] =((motorPos1[j]==motorPos2[j]) && (motorPos1[j+1]==motorPos2[j+1]) && (motorPos1[j+2]==motorPos2[j+2]));
                motorPos.push_back(m);
                //cout << b[i] << endl;
                j=j+3;
            } 
            
            /*
            j = 0;
            for(int i= 0; i<COUNT; i++){
                cout <<"Position "<< i+1 << ":" << endl;
                cout << "a :" << motorPos1[j] <<"|" << motorPos2[j] << endl;
                cout << "b :" << motorPos1[j+1] <<"|" << motorPos2[j+1] << endl;
                cout << "c :" << motorPos1[j+2] <<"|" << motorPos2[j+2] << endl;
                j++;
            }
            */
            
            if(b[0] && b[1] && b[2] && b[3] && b[4] && b[5] && b[6] &&  b[7] && b[8] && b[9]){
                robot.drive(motorPos);
            }
            
          
    }
    munmap(memory1, 2048*sizeof(double));
    shm_unlink("/shm1");
    munmap(memory2, 2048*sizeof(double));
    shm_unlink("/shm2");
    return 0;
}

int makeChilds(int n, pid_t *pid){
    for(int i=0; i < n; i++){
        switch( pid[i] = fork() ){
            case -1:
                return -1;
            case 0:
                return 0;
            default:;
        }
    }
    return 1;
}
//child 1
vector<MotorPos> runR(double *s){
    
    //cout << "child 1 :" << getpid() << endl;
    
    Vector start (10.0,11.0,150.0);
    Vector end (20.0,-10.0,160.0);
    Robot robot (233.0, 147.0 ,60.0);
    std::vector<Vector> line;
    std::vector<MotorPos> motorPos;
    
    line = start.linear(end, COUNT);
    
    motorPos = robot.inverse(line);
    int j = 0;
    
    //in Arry schreiben
    for(int i=0; i<COUNT; i++){
        s[j] = motorPos[i].getA();
        s[j+1] = motorPos[i].getB();
        s[j+2] = motorPos[i].getC();
        j=j+3;
    }
    
    return motorPos;
}
//child 2
vector<MotorPos> runV(double *s){
    
    //cout << "child 2 :" << getpid() << endl;
    
    coord start(10.0,11.0,150.0);
    coord end(20.0,-10.0,160.0);
    
    std::vector<coord> c;

    vektor v(start,end);
    c = v.linear(start,end);
    int j = 0;
    
    //in Arry schreiben
    for(int i=0; i<COUNT; i++){
        s[j] = c[i].getX();
        s[j+1] = c[i].getY();
        s[j+2] = c[i].getZ();
        j=j+3;
    }
}