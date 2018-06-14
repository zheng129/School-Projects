//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>

using namespace std;

/*
* The header file for the Menu class
*/
class Menu{

private:
  int response; // the answer from user
  
public:
  Menu(); // Constructor
  ~Menu(); // Destructor

  void welcome(); // start the program
  void displayMenu(); // display the menu
};
