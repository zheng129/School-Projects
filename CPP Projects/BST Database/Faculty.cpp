//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "Faculty.h"

/*
* The Faculty class, contains a object of a Faculty
*/
using namespace std;

/*
* Constructor
*/
Faculty :: Faculty(){};

/*
* Overridden Constructor, a Faculty object has id, name, level, and department
*/
Faculty::Faculty(int i, string n, string l, string d){
  id = i;
  name = n;
  level = l;
  department = d;
  adviseeIDArray = new int[4];
  numAdvisees = 0;
  maxArraySize = 4;

  for (int i = 0; i < 4; ++i){
    adviseeIDArray[i] = -1;
  }
}

/*
* Destructor, deletes the advisee array
*/
Faculty :: ~Faculty(){
  delete [] adviseeIDArray;
};

/*
* prints out the information for faculty
*/
void Faculty::printFaculty(){
  cout << "Faculty ID: " << id << " | Name: " << name << " | Level: " << level << " | Dept: " << department << "\nAdvisee IDs: ";
  printAdvisees();
  cout << endl;
}

/*
* prints out the inforamtion of advisees
*/
void Faculty::printAdvisees(){
  if (numAdvisees == 0){
    cout << "No Advisees";
  }

  // GO THROUGH ADVISEE LIST AND PRINT ID OF ALL
  else{
    for (int i = 0; i < maxArraySize; ++i){
      if (adviseeIDArray[i] != -1){
        cout << adviseeIDArray[i];
        if (i < numAdvisees - 1){
          cout << ", ";
        }
      }
    }
  }

  cout << endl;
}

/*
* add an advisee for a faculty
*/
void Faculty::addAdvisee(int aid){

  if (numAdvisees == maxArraySize){
    int *temp1 = new int[numAdvisees];


    for (int i = 0; i < numAdvisees; ++i){
      temp1[i] = adviseeIDArray[i];
    }


    adviseeIDArray = new int[numAdvisees * 2];

    maxArraySize = numAdvisees * 2;


    for (int i = 0; i < numAdvisees; ++i){
      adviseeIDArray[i] = temp1[i];
    }

    for (int i = numAdvisees; i < numAdvisees * 2; ++i){
      adviseeIDArray[i] = -1;
    }

    adviseeIDArray[++numAdvisees] = aid;
  }


  else{
    int f = 0;

    for (int i = 0; i < maxArraySize; ++i)
    {
      if (adviseeIDArray[i] == aid)
      {
        f = maxArraySize;
      }
    }

    while (f < maxArraySize)
    {
      if (adviseeIDArray[f] == -1)
      {
        adviseeIDArray[f] = aid;

        ++numAdvisees;

        break;
      }

      ++f;
    }
  }
}

/*
* removes a advisee for a faculty
*/
bool Faculty::removeAdvisee(int adviseeID){
  bool deleted = false;


  for (int i = 0; i < maxArraySize; ++i){
    if (adviseeIDArray[i] == adviseeID){
      adviseeIDArray[i] = -1;
      --numAdvisees;
      deleted = true;
    }
  }

  if (!deleted){
    cout << "\nAdvisee not found." << endl;
  }

  return deleted;
}

/*
* returns the max size of the advisees array
*/
int Faculty :: getMaxArraySize(){
  return maxArraySize;
}

/*
* returns the department the falcuty
*/
string Faculty :: getDepartment(){
  return department;
}

/*
* returns the number of advisees of the falcuty
*/
int Faculty :: getNumAdvisees(){
  return numAdvisees;
}
