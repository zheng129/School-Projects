//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <iostream>

/*
* The header file of Student
*/
class Student{

  public:
    Student(); // Constructor
    ~Student(); // Destructor
    Student(int t, int e); //Overridden Constructor

    int timeAtWindow; // keep track of time student at window
    int entryTime; // keep track of the time student enters
    int timeInQueue; // keep track of the time student in queue
    int idleTime; // keep track of the time window idle
};
