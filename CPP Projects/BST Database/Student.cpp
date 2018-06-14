//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "Student.h"

/*
* The Student class, contains a object of a Student
*/
using namespace std;

/*
* Constructor
*/
Student :: Student(){};

/*
* Overridden Constructor, a Student object has id, name, level, gpa, major, and advisor ID
*/
Student::Student(int i, string n, string l, double g, string m, int a){
  id = i;
  name = n;
  level = l;
  gpa = g;
  major = m;
  advisorID = a;
}

/*
* Destructor, does not do much
*/
Student :: ~Student(){};

/*
* set up a new advisor for a stduent
*/
void Student :: setAdvisorID(int aid){
  advisorID = aid;
}

/*
* returns student's advisor's ID
*/
int Student :: getAdvisorID(){
  return advisorID;
}

/*
* prints out student's information
*/
void Student :: printStudent(){

  cout << "Student ID: " << id << " | Name: " << name << " | Grade: " << level << " | GPA: " << gpa << " | Major: " << major << " | Advisor ID: ";

  if (advisorID == -1){
    cout << "No Advisor" << endl;
  }

  else{
    cout << advisorID << endl;
  }
}

/*
* returns student's GPA
*/
double Student :: getGPA(){
  return gpa;
}

/*
* returns student's major
*/
string Student :: getMajor(){
  return major;
}
