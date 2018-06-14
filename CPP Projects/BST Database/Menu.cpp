//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "Menu.h"

/*
* The Menu class, shows the options for the users
*/
using namespace std;

/*
* Constructor
*/
Menu :: Menu(){};

/*
* Destructor, does not do much
*/
Menu :: ~Menu(){};

/*
* the method initiate the program
*/
void Menu::welcome(){
  cout << "\nStudent & Faculty Records Database\n----------------------------------\n";
  displayMenu();
}
/*
* prints out the options for the user to choose from
*/
void Menu :: displayMenu(){

  cout << "\n1.  Print all students and their information" << endl;
  cout << "2.  Print all faculty and their information" << endl;
  cout << "3.  Find and display student information" << endl;
  cout << "4.  Find and display faculty information" << endl;
  cout << "5.  Get faculty advisor of student" << endl;
  cout << "6.  Get advisees of a faculty member" << endl;
  cout << "7.  Add a new student" << endl;
  cout << "8.  Delete a student" << endl;
  cout << "9.  Add a new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student’s advisor" << endl;
  cout << "12. Remove an advisee from a faculty member" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
}
