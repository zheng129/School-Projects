//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>
#include <array>
#include "DLL.h"
#include "Person.h"

using namespace std;

/*
* The header file of Faculty
*/
class Faculty : public Person{

public:
  string department; // faculty's Department
  unsigned int numAdvisees; // faculty's advisees
  unsigned int maxArraySize; // the maximum size of the array of advisees
  int *adviseeIDArray; // the advisee's array

  Faculty(); // Constructor
  Faculty(int i, string n, string l, string d);
  ~Faculty(); // Destructor

  void printFaculty(); // print out faculty's information
  void printAdvisees(); // print out advisee's information

  void addAdvisee(int aid); // add an advisee for a faculty
  bool removeAdvisee(int adviseeID); // remove an advisee for a faculty

  int getMaxArraySize(); // get the max size of the advisee array
  string getDepartment(); // get faculty's department
  int getNumAdvisees(); // get the number of advisee's of a faculty
};
