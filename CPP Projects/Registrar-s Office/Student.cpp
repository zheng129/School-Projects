//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <iostream>
#include "Student.h"

/*
* The Student class, contains a object of a Student
*/
using namespace std;

/*
* Constructor, a Student object has a time at window, time entered, time in queue, and window idle
*/
Student :: Student(){
    timeAtWindow = 0;
    entryTime = 0;
    timeInQueue = 0;
    idleTime = 0;
}

/*
* Destructor, does not do much
*/
Student :: ~Student(){};

/*
* Overridden Constructor, set time at window and time entered to paramaters
*/
Student :: Student(int t, int e){
    timeAtWindow = t;
    entryTime = e;
    timeInQueue = 0;
    idleTime = 0;
}
