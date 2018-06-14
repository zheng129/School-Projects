//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "Processor.h"

/*
* the main class, runs the program
*/
using namespace std;

/*
* the main method, the origin of everything
*/
int main (int argc, char** argv){
  Processor p1;
  Menu menu;
  
  p1.readFromFile();
  menu.welcome();
  p1.run();
  p1.writeToFile();

  return 0;
}
