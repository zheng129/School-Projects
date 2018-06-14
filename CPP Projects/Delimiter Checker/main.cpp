//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 3

#include <iostream>
#include "genstack.h"
#include <string>

using namespace std;

/*
* The main function to run the program
* Calls choices funtion for user to start checking files
* Cannot have stack overflow for the stack so the initial size
* for the stack is set to 50
*/
int main(int argc, char **argv){

  genstack<char> myStack(50); // Initialize a char stack

  myStack.choices(); // Call my choices

  return 0;
}
