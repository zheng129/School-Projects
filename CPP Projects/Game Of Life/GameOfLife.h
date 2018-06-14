//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 2

// the header file of the game of Life
#ifndef MY_HEADER_FILE
#define MY_HEADER_FILE

#include <iostream>
#include <string>
#include <fstream>

const int X = 1; // X is set to 1
const int dash = 0; // dash is set to 0

class GameOfLife {

public:
  GameOfLife(); // constructor
  ~GameOfLife(); // destructor

  void choices(); // take user's choice of read a map or generate a random map
  void setSizes(); // set the size of the grid based on the map
  void generateArrays(); // generate the grid based on the map
  void fillArrayInitial(int **arr); // filling arrays initially with X's and dashes
  void fillArraySides(int **arr); // filling the sides of the array depends on mode the user choose
  void copyArray(int **arr1, int **arr2); // copies old array to a new array
  void checkIfEmpty(int **arr); // checks if the array is empty
  bool checkIfStable(int **arr1, int **arr2); //checks if the array is stable
  void pauseEnterOrOutput(); // checks the user's choice for pause, wait for enter, or output to file

  void preparation(); // set up the game for running
  void playGame(); // runs the game
  void printArray(int **arr); // prints the array on console
  void printArrayUtility(); // general print array function
  void printEntireArray(); // general funtion prints out the whole array
  void printToFile(int **arr); //prints out the result to an output file

private:
  int **originalArray; // the original array from file
  int originalArrayRows; // the original row size
  int originalArrayColumns; // the original column size

  int arrayRows; // original row size + 2 for the outer grid
  int arrayColumns; // original column size + 2 for the outer grid

  int **currentArray; // the array for current generation
  int **nextArray; // the array for next generation

  char mode; // for checking the mode option: Classic, Doughnut, Mirror
  char output; // for checking the output option: pause automatically, wait for enter, output to a file

  float density; // for calculating the population of the random genarated grid

  std::string outputFileString; // output stream name
  std::ofstream outputFileStream; // output stream

  std::string inputFileString; // input stream name
  std::ifstream inputFileStream; //input stream

  bool readFile; // checks if it is read from a file
  bool originalArrayExists; // checks if the original array exists

  int generation; // the number of generations
  int X_count; // the count of X on the grid

};
#endif
