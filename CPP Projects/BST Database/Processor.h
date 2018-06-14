//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "Menu.h"

using namespace std;

class Processor{

public:
  BST<Student> masterStudent; // a tree for student
  BST<Faculty> masterFaculty; // a tree for faculty

  Processor(); // Constructor
  ~Processor(); // Destructor

  void readFromFile(); // read form file and add into the tree
  void writeToFile(); // write the data in the tree into a file

  void printMasterStudent(TreeNode<Student> *n); // print the student tree
  void printMasterFaculty(TreeNode<Faculty> *n); // print the faculty tree

  void outputMasterStudent(TreeNode<Student> *n, string s); // output student's information to the file
  void outputMasterFaculty(TreeNode<Faculty> *n, string s); // output faculty's information to the file

  void displayStudentInfo(int i); // print out student's informtion given student ID
  void displayFacultyInfo(int i); // print out faculty's information given faculty ID

  void addStudent(); // add a student to the tree
  void addFaculty(); // add a faculty to the tree

  void addStudentFromFile(int i, string n, string l, double g, string m, int a); // add a student to the tree from a file
  void addFacultyFromFile(int i, string n, string l, string d); // add a faculty to the tree from a file

  TreeNode<Student>* getMasterStudentRoot(); // get the root of student tree
  TreeNode<Faculty>* getMasterFacultyRoot(); // get the root of faculty tree

  int checkInput(int lowerEnd, int upperEnd, string msg); // check if user input is valid

  void run(); // run the program
};
