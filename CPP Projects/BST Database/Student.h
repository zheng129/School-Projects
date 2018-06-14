//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>
#include "Person.h"

using namespace std;

/*
* The header file of Student
*/
class Student : public Person{

public:
  Student(); //Constructor
  Student(int i, string n, string l, double g, string m, int a);//Overridden Constructor
  ~Student(); // Destructor

  void setAdvisorID(int aid); // set up student's advisor by his/her ID
  void printStudent(); // print out student's information

  double getGPA(); // get student's GPA
  string getMajor(); // get student's major
  int getAdvisorID(); // get student's advisor's ID

  double gpa; // student's GPA
  string major; // student's major
  int advisorID; // student's advisor's ID
};
