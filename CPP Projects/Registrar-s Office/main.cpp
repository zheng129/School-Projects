//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <iostream>
#include "Simulation.h"

using namespace std;

/*
* The main method that check argument, reads file to the program
* and calls functions to calculate the time for student and window
*/
int main(int argc, char** argv){
  Simulation simulation;

  int currentTime = 0;
  int openWindows = 0;
  bool stopRunning = false;

  if (argc == 2){
    if (simulation.readFile(argv[1])){
      while (!stopRunning){

        if (simulation.studentQueue.isEmpty()){
          int t = 0;

          for (int i = 0; i < simulation.totalNumWindows; ++i){
            if ((simulation.windowArray[i] -> timeAtWindow) < 1){
              t++;
            }
          }

          if (t == simulation.totalNumWindows){
            stopRunning = true;
          }
        }

        for (int i = 0; i < simulation.totalNumWindows; ++i){

          if (simulation.windowArray[i] -> timeAtWindow < 1){

            if (!simulation.studentQueue.isEmpty()){

              Student* student = simulation.studentQueue.getFront();

              if (student -> entryTime <= currentTime){

                if (simulation.windowArray[i] -> idleTime > 0){

                  simulation.idleTimeStatsList.insert(simulation.windowArray[i] -> idleTime);
                }

                simulation.windowArray[i] = simulation.studentQueue.remove();

                simulation.waitTimeStatsList.insert(simulation.windowArray[i] -> timeInQueue);
              }
            }
          }
        }
        currentTime++;
        simulation.incrementAllTimes(currentTime);
      }

      for (int i = 0; i < simulation.totalNumWindows; ++i){
        if (simulation.windowArray[i] -> idleTime > 0){
          simulation.idleTimeStatsList.insert(simulation.windowArray[i] -> idleTime);
        }
      }
      simulation.setMinutesMessage(currentTime);

      cout << "\nSimulation completed after " << currentTime << simulation.getMinutesMessage() << ". " << simulation.totalStudents << simulation.getStudentsMessage() << endl;
      cout << "Mean student wait time:    " << simulation.calcMeanWait() << simulation.getMinutesMessage() << endl;
      cout << "Median student wait time:  " << simulation.calcMedianWait() << simulation.getMinutesMessage() << endl;
      cout << "Longest student wait time: " << simulation.calcLongestWait() << simulation.getMinutesMessage() << endl;
      cout << "Waits over 10 minutes:     " << simulation.calcNumWaitsOverTen() << simulation.getMinutesMessage() << endl;
      cout << "Mean window idle time:     " << simulation.calcMeanIdle() << simulation.getMinutesMessage() << endl;
      cout << "Longest window idle time:  " << simulation.calcLongestIdle() << simulation.getMinutesMessage() << endl;
      cout << "Idle times over 5 minutes: " << simulation.calcNumIdleOverFive() << simulation.getMinutesMessage() << endl << endl;
    }

    else{
      if (simulation.showFileLoadingErrors){
        cout << "\nFile not Found.\n\nProgram Ended.\n" << endl;
      }
    }
  }
  
  return 0;
}
