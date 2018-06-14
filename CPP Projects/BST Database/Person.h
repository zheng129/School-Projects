//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>
#ifndef included
#define included

using namespace std;

/*
* The header file of Person
*/
class Person{

public:
  Person(); // Constructor
  ~Person(); // Destructor

  int getID(); // get person's ID
  void setID(int v); // set up a person's ID

  string getName(); // get a person's name
  string getLevel(); // get a person's level

  int id; // a person's ID
  string name; // a person's name
  string level; // a person's level
};

#endif
