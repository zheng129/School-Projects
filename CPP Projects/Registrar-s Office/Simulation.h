//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <string>
#include "Queue.h"
#include "Student.h"

using namespace std;

/*
* The header file of Simulation
*/
class Simulation{
public:
  Simulation(); // Constructor
  ~Simulation(); // Destructor

  bool readFile(string s); // read the given file
  bool incrementAllTimes(int c); // check and change the time for student and window

  double calcMeanWait(); // calculate the mean wait time
  double calcMedianWait(); // calculate the median wait time
  int calcLongestWait(); // calculate the longest wait time
  int calcNumWaitsOverTen(); // calculate the wait time over 10 minutes

  double calcMeanIdle(); // calculate the mean idle time
  int calcLongestIdle(); // calculate the longest idle time
  int calcNumIdleOverFive(); // calculate the idle time over 10 minutes

  string getMinutesMessage(); // gets the message string
  void setMinutesMessage(int t); // distinguish "minute" and "minutes" for differnt data
  string getStudentsMessage(); // distinguish "student" and "students" based on the number of student

  Student* *windowArray; // the array for window

  Queue<Student*> studentQueue; // the queue of student

  Queue<int> waitTimeStatsList; // a queue for wait times
  Queue<int> idleTimeStatsList; // a queue for idle times

  int *medianArray; // a array for calculate meadian
  int *idleArray; // a array for calculate idle time

  int totalNumWindows; // the number of windows
  int totalStudents; // the number of students

  bool showFileLoadingErrors; // check if the file is loaded correctly

private:
  int lineType; // distinguish the different type of lines to know what data it is, and where to take it
  int studentEntryTime; // the time student entered
  int studentTimeAtWindow; // the time student at windows
  int numStudentsAtClockTick; // the time next student arrives
  int medianArrayElementsCount; // element for calculating the median wait time
  int idleArrayElementsCount; // element for calculating the idle time
  string messageString; // helping print out the time in minutes
};
