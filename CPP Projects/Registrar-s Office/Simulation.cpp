//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include "Simulation.h"

/*
* The Simulation class, contains a object of a Simulation
*/
using namespace std;

/*
* Constructor, a Simulation object is initialized
*/
Simulation :: Simulation(){

  lineType = 1;
  studentEntryTime = 0;
  studentTimeAtWindow = 0;
  numStudentsAtClockTick = 0;

  medianArrayElementsCount = 0;
  idleArrayElementsCount = 0;

  totalNumWindows = 0;
  totalStudents = 0;

  showFileLoadingErrors = true;
  messageString = " minutes";
}

/*
* Destructor, delete arrays that do not have use anymore
*/
Simulation :: ~Simulation(){

  delete [] windowArray;
  delete [] medianArray;
  delete [] idleArray;
}

/*
* Reads file and sets everything up
*/
bool Simulation :: readFile(string f){

  ifstream inputFile;
  inputFile.open(f.c_str());
  string line;
  int lineNumber = 1;

  if (inputFile.is_open()){
    try{
      getline(inputFile, line);
      totalNumWindows = stoi(line);

      windowArray = new Student*[totalNumWindows];
      for (int i = 0; i < totalNumWindows; ++i){
        Student* student = new Student();
        windowArray[i] = student;
      }
      lineNumber++;
    }

    catch (exception e){
      cout << "\nERROR ON LINE " << lineNumber << ": TOTAL NUMBER OF WINDOWS INCORRECT FORMAT\n" << endl;
      showFileLoadingErrors = false;
      return false;
    }

    while (getline(inputFile, line)){
      switch (lineType){
        case (1):{
          try{
            studentEntryTime = stoi(line);

            lineType++;
            lineNumber++;
          }

          catch (exception e){
            cout << "\nERROR ON LINE " << lineNumber << ": CLOCK TICK IS INCORRECT FORMAT\n" << endl;
            showFileLoadingErrors = false;
            return false;
          }
          break;
        }

        case (2):{
          try{
            if (line != ""){
              numStudentsAtClockTick = stoi(line);

              for (int i = 0; i < numStudentsAtClockTick; ++i){
                getline(inputFile, line);
                lineNumber++;

                try{
                  studentTimeAtWindow = stoi(line);
                }

                catch(exception e){
                  cout << "\nERROR ON LINE " << lineNumber << ": STUDENT TIME AT WINDOW INCORRECT FORMAT\n" << endl;
                  showFileLoadingErrors = false;
                  return false;
                }
                totalStudents++;

                Student* student = new Student(studentTimeAtWindow, studentEntryTime);
                studentQueue.insert(student);
              }
              lineType = 1;
            }
          }

          catch (exception e){
            cout << "\nERROR ON LINE " << lineNumber << ": NUM STUDENTS IS INCORRECT FORMAT\n" << endl;
            showFileLoadingErrors = false;
            return false;
          }
          break;
        }
        default:
        break;
      }
    }
  }

  else{
    return false;
  }
  return true;
}

/*
* Check and change the time for student and window
*/
bool Simulation :: incrementAllTimes(int c){
  for (int i = 0; i < totalNumWindows; ++i){
    if (windowArray[i] -> timeAtWindow > 0){
      windowArray[i] -> timeAtWindow--;
    }

    else{
      windowArray[i] -> idleTime++;
    }
  }

  if (!studentQueue.isEmpty()){
    ListNode<Student*> *curr = studentQueue.front;

    while (curr != NULL){
      if (curr -> data -> entryTime < c){
        curr -> data -> timeInQueue += 1;
      }
      curr = curr -> next;
    }
  }
  return true;
}

/*
* Calculate the mean wait time
*/
double Simulation :: calcMeanWait(){
  ListNode<int> *curr = waitTimeStatsList.front;

  double meanWait = 0;
  int sum = 0;
  int count = 0;

  while (curr != NULL){
    sum += curr -> data;
    curr = curr -> next;
    count++;
  }

  if (count == 0){
    setMinutesMessage(0);
    return 0;
  }

  meanWait = double(sum) / double(count);
  setMinutesMessage(meanWait);
  return meanWait;
}

/*
* Calculate the median wait time
*/
double Simulation :: calcMedianWait(){
  ListNode<int> *curr = waitTimeStatsList.front;

  double medianWait = 0;
  medianArrayElementsCount = 0;

  while (curr != NULL){
    curr = curr -> next;
    medianArrayElementsCount++;
  }

  if (medianArrayElementsCount == 0){
    setMinutesMessage(0);
    return 0;
  }

  else{
    medianArray = new int[medianArrayElementsCount];
    curr = waitTimeStatsList.front;

    for (int i = 0; i < medianArrayElementsCount; ++i){
      medianArray[i] = curr -> data;
      curr = curr -> next;
    }

    sort(medianArray, medianArray + medianArrayElementsCount);

    // for odd numbers
    if (medianArrayElementsCount % 2 == 1){
      double d = 0;
      int t = 0;

      t = (medianArrayElementsCount / 2) + 1;
      d = medianArray[t];

      setMinutesMessage(d);
      return d;
    }

    // for even numbers
    else{
      double d = 0;
      int t1 = 0;
      int t2 = 0;

      t1 = medianArrayElementsCount / 2;
      t2 = (medianArrayElementsCount / 2) + 1;

      if (medianArray[t2] == 0){
        setMinutesMessage(0);
        return 0;
      }

      d = double(medianArray[t1]) / double(medianArray[t2]);
      setMinutesMessage(d);
      return d;
    }
  }
}

/*
* Calculate the longest wait time
*/
int Simulation :: calcLongestWait(){

  if (medianArrayElementsCount != 0){
    setMinutesMessage(medianArray[medianArrayElementsCount - 1]);
    return medianArray[medianArrayElementsCount - 1];
  }

  else{
    setMinutesMessage(0);
    return 0;
  }
}

/*
* Calculate the number of wait time over 10 minutes
*/
int Simulation :: calcNumWaitsOverTen(){

  if (medianArrayElementsCount != 0){
    int c = 0;

    for (int i = 0; i < medianArrayElementsCount; ++i){
      if (medianArray[i] > 10){
        ++c;
      }
    }
    setMinutesMessage(c);
    return c;
  }

  else{
    setMinutesMessage(0);
    return 0;
  }
}

/*
* Calculate the mean idle time
*/
double Simulation :: calcMeanIdle(){
  ListNode<int> *curr = idleTimeStatsList.front;

  double meanIdle = 0;
  int sum = 0;
  int count = 0;

  while (curr != NULL){
    sum += curr -> data;
    curr = curr -> next;
    count++;
  }

  if (count == 0){
    setMinutesMessage(count);
    return 0;
  }

  meanIdle = double(sum) / double(count);

  setMinutesMessage(meanIdle);
  return meanIdle;
}

/*
* Calculate the longest idle time
*/
int Simulation :: calcLongestIdle(){
  ListNode<int> *curr = idleTimeStatsList.front;
  idleArrayElementsCount = 0;

  while (curr != NULL){
    curr = curr -> next;
    idleArrayElementsCount++;
  }

  idleArray = new int[idleArrayElementsCount];
  curr = idleTimeStatsList.front;

  for (int i = 0; i < idleArrayElementsCount; ++i){
    idleArray[i] = curr -> data;
    curr = curr -> next;
  }

  sort(idleArray, idleArray + idleArrayElementsCount);
  setMinutesMessage(idleArray[idleArrayElementsCount - 1]);
  return (idleArray[idleArrayElementsCount - 1]);
}

/*
* Calculate the number of idle time over 5 minutes
*/
int Simulation :: calcNumIdleOverFive(){
  int c = 0;

  for (int i = 0; i < idleArrayElementsCount; ++i){
    if (idleArray[i] > 5){
      ++c;
    }
  }

  setMinutesMessage(c);
  return c;
}

/*
* Returns the message string
*/
string Simulation :: getMinutesMessage(){
  return messageString;
}

/*
* Specifies the use of single or plural words in message string when printing
*/
void Simulation :: setMinutesMessage(int t){
  if (t != 1){
    messageString = " minutes";
  }

  else {
    messageString = " minute";
  }
}

/*
* Specifies the use of single or plural words in sentence when printing
*/
string Simulation :: getStudentsMessage(){
  if (totalStudents != 1){
    return (" students were helped.\nResults");
  }

  else{
    return (" student was helped.\nResults");
  }
}
