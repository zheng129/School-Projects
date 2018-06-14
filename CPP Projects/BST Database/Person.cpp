//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "Person.h"

/*
* The Person class, contains a object of a Person
*/
using namespace std;

/*
* Constructor
*/
Person :: Person(){};

/*
* Destructor, does not do much
*/
Person :: ~Person(){};

/*
* returns a person's ID
*/
int Person :: getID(){
  return id;
}

/*
* set a person's ID
*/
void Person :: setID(int v){
  id = v;
}

/*
* returns a person's name
*/
string Person :: getName(){
  return name;
}

/*
* returns a person's level
*/
string Person :: getLevel(){
  return level;
}
