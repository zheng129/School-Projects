//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 2

#include "GameOfLife.h" // including the header file
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

/*
* Constructor, Initializes values for variables
*/
GameOfLife :: GameOfLife(){
  density = 0;
  X_count = 0;
}

/*
* Destructor, closes files, delete arrays, and return memory
*/
GameOfLife :: ~GameOfLife(){

  if (outputFileStream.is_open()){
    outputFileStream.close();
  }
  if(inputFileStream.is_open()){
    inputFileStream.close();
  }

  for (int i = 0; i < arrayRows; ++i){
    delete [] originalArray[i];
    delete [] currentArray[i];
    delete [] nextArray[i];
  }

  delete [] originalArray;
  delete [] currentArray;
  delete [] nextArray;

}

/*
* Asks the player for read or generate map, and what mode they would like to play
*/
void GameOfLife :: choices(){
  string choice;

  while ((choice != "read") && (choice != "random")){
  cout << "Would you like to upload a file for map or have a random generation?\n " << endl;
  cout << "Answer 1) 'read' for reading a map\n       2) 'random' for a genarated map. " << endl;
  cin >> choice;
}

  if (choice == "read"){
    readFile = true;
    cout << "Please enter the full name of the file, including the .txt at the end. " << endl;
    cin >> inputFileString;
    inputFileStream.open(inputFileString.c_str());

    setSizes();

  }
  if (choice == "random"){
    setSizes();
  }

  while ((mode != 'c') && (mode != 'd') && (mode != 'm')){
  cout << "Which mode would you like to choose: \nClassic - 'c', \nDoughnut - 'd', \nor Mirror? - 'm'." << endl;
  cin >> mode;
}

  while ((output != 'p') && (output != 'e') && (output != 'o')){
  cout << "Would you prefer the game to pause automatically - 'p', \nhave you press 'enter' to process - 'e', \nor output results to a file? - 'o'" << endl;
  cin >> output;
}

  if ((output == 'o') || (output == 'O')){
    cout << "Please enter the name of the file you would like to output to: " << endl;
    cin >> outputFileString;
    outputFileStream.open(outputFileString.c_str(), ios::out | ios::app);
  }
}

/*
* Sets the sizes of the array
* If the player choose to read, set up the dimentions of the array while keeping track of the original sizes
* If the player choose to generate a ramdom grid, asks for dimentions of the grid as well as density
*/
void GameOfLife :: setSizes(){
  if(inputFileStream.is_open()){

    string line;
    getline (inputFileStream, line);
    originalArrayRows = atoi(line.c_str());
    getline (inputFileStream, line);
    originalArrayColumns = atoi(line.c_str());

    arrayRows = originalArrayRows + 2;
    arrayColumns  = originalArrayColumns + 2;

    }
    else {

      cout << "Please enter height of the random grid: " << endl;
      cin >> originalArrayRows;

      cout << "Please enter width of the random grid: " << endl;
      cin >> originalArrayColumns;

      arrayRows = originalArrayRows + 2;
      arrayColumns  = originalArrayColumns + 2;

      cout << "Please enter the density of the grid." << endl;
      cout << "The density should be a decimal number between 0 and 1." << endl;
      cin >> density;
    }
}

/*
* Initializes arrays. These arrays will be destructed later
*/
void GameOfLife :: generateArrays(){
  originalArrayExists = true; // checks if the original array exists

  originalArray = new int*[arrayRows];
  for (int i = 0; i < arrayRows; ++i){
    originalArray[i] = new int[arrayColumns];
  }

  currentArray = new int*[arrayRows];
  for (int j = 0; j < arrayRows; ++j){
    currentArray[j] = new int[arrayColumns];
  }

  nextArray = new int*[arrayRows];
  for (int k = 0; k < arrayRows; ++k){
    nextArray[k] = new int[arrayColumns];
  }
}

/*
* Fills in the array for the first time, based on either a file or random grid.
*/
void GameOfLife :: fillArrayInitial(int **arr){
  string line;

  if (readFile){
    for (int i = 1; i < arrayRows - 1; ++i){
      getline (inputFileStream, line);

      for (int j = 1; j < arrayColumns - 1; ++j){
        if ((line[j - 1] == 'X')|| (line[j - 1] == 'x')){
          arr[i][j] = X;
        }
        else if (line[j - 1] == '-'){
          arr[i][j] = dash;
        }
      }
    }
  }

  else if (density > 0){
      int row = 0;
      int col = 0;
      int population = (originalArrayRows * originalArrayColumns) * (density);

      for (int i = 1; i < arrayRows - 1; ++i){
        for (int j = 1; j < arrayColumns - 1; ++j){
          arr[i][j] = dash;
        }
      }

      while (population > 0){
        row = rand() % originalArrayRows + 1;
        col = rand() % originalArrayColumns + 1;

        if (arr[row][col] != X){
          arr[row][col] = X;
          --population;
        }
      }
    }
  }

  /*
  * Fills in the sides of the array based on the mode player choses
  */
void GameOfLife :: fillArraySides(int **arr){
    if ((mode == 'c') || (mode == 'C')){ // Classic mode
      for (int i = 0; i < arrayRows; ++i){
        for (int j = 0; j < arrayColumns; ++j){
          if ((i == 0) || (i == arrayRows - 1)){
            arr[i][j] = dash;
          }
          if ((j == 0) || (j == arrayColumns - 1)){
            arr[i][j] = dash;
          }
        }
      }
    }

    if ((mode == 'd') || (mode == 'D') || (mode == 'm') || (mode == 'M')){ // either Doughnut or Mirror
      for (int i = 0; i < arrayRows - 1; ++i){
        for (int j = 0; j < arrayColumns - 1; ++j){

          if ((i == 1) && (j == 1)){ //top left corner
            if ((mode == 'd') || (mode == 'D')){ // Doughnut
              arr[i - 1][j - 1] = arr[arrayRows - 2][arrayColumns - 2];
            }
            if ((mode == 'm') || (mode == 'M')){ // Mirror
              arr[i - 1][j - 1] = arr[i][j];
              arr[i - 1][j] = arr[i][j];
              arr[i][j - 1] = arr[i][j];
            }
          }

          if ((i == 1) && (j > 1) && (j < arrayColumns - 2)){ // top middle section
            if ((mode == 'd') || (mode == 'D')){ // Doughnut
              arr[i - 1][j - 1] = arr[arrayRows - 2][j - 1];
              arr[i - 1][j] = arr[arrayRows - 2][j];
              arr[i - 1][j + 1] = arr[arrayRows - 2][j + 1];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i - 1][j] = arr[i][j];
          }
        }

        if ((i == 1) && (j == arrayColumns -2)){ // top right corner
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i - 1][j + 1] = arr[arrayRows - 2][1];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i - 1][j] = arr[i][j];
            arr[i - 1][j + 1] = arr[i][j];
            arr[i][j + 1] = arr[i][j];
          }
        }

        if ((i > 1) && (i <  arrayRows - 2) && (j == arrayColumns - 2)){ // right side middle
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i - 1][j + 1] = arr[i - 1][1];
            arr[i][j + 1] = arr[i][1];
            arr[i + 1][j + 1] = arr[i + 1][1];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i][j + 1] = arr[i][j];
          }
        }

        if ((i == arrayRows - 2) && (j == arrayColumns - 2)){ // bot right corner
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i + 1][j + 1] = arr[1][1];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i][j + 1] = arr[i][j];
            arr[i + 1][j + 1] = arr[i][j];
            arr[i + 1][j] = arr[i][j];
          }
        }

        if ((i <  arrayRows - 2) && (j == arrayColumns - 2) && (j > 1)){ // bottom side
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i + 1][j + 1] = arr[1][j + 1];
            arr[i + 1][j] = arr[1][j];
            arr[i + 1][j - 1] = arr[1][j - 1];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i + 1][j] = arr[i][j];
          }
        }

        if ((i == arrayRows - 2) && (j == 1)){ // bottom left corner
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i + 1][j - 1] = arr[1][arrayColumns - 2];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i + 1][j] = arr[i][j];
            arr[i + 1][j - 1] = arr[i][j];
            arr[i][j - 1] = arr[i][j];
          }
        }

        if ((i <  arrayRows - 2) && (i > 1) && (j == 1)){ // left side middle
          if ((mode == 'd') || (mode == 'D')){ // Doughnut
            arr[i + 1][j - 1] = arr[i + 1][arrayColumns - 2];
            arr[i][j - 1] = arr[i][arrayColumns - 2];
            arr[i - 1][j - 1] = arr[i - 1][arrayColumns - 2];
          }
          if ((mode == 'm') || (mode == 'M')){ // Mirror
            arr[i][j - 1] = arr[i][j];
          }
        }
      }
    }
  }
  }

  /*
  * Checks if the array is empty
  */
  void GameOfLife :: checkIfEmpty(int **arr){
    int result = 0;
    for (int i = 0; i < arrayRows; ++i){
      for (int j = 0; j < arrayColumns; ++j) {
        if (arr[i][j] == X){
          result += 1;
        }
      }
    }
    X_count = result;
  }

  /*
  * Checks if the array is stable
  */
  bool GameOfLife :: checkIfStable(int **arr1, int **arr2){
    for (int i = 0; i < arrayRows; ++i){
      for (int j = 0; j < arrayColumns; ++j) {
        if (arr1[i][j] != arr2[i][j]){
          return false;
        }
      }
    }
    return true;
  }

  /*
  * Copies the info of an array to another
  */
  void GameOfLife :: copyArray(int **from, int **to){
    for (int i = 0; i < arrayRows; ++i){
      for (int j = 0; j < arrayColumns; ++j) {
        if(from[i][j] == X){
          to[i][j] = X;
        }
        else if (from[i][j] == dash){
          to[i][j] = dash;
        }
      }
    }
  }

  /*
  * Prints out the array
  */
  void GameOfLife :: printArray(int **arr){
    cout << generation << endl;
    for (int i = 1; i < arrayRows - 1; ++i){
      for (int j = 1; j < arrayColumns - 1; ++j){
        if (arr[i][j] == X){
          cout << "X";
        }
        else if (arr[i][j] == dash){
          cout << "-";
        }
      }
      cout << endl;
    }
    ++generation;
  }

  /*
  * General function for print out array
  */
  void GameOfLife :: printArrayUtility(){
    cout << generation << endl;
    for (int i = 1; i < arrayRows - 1; ++i){
      for (int j = 1; j < arrayColumns - 1; ++j){
        if (currentArray[i][j] == X){
          cout << "X";
        }
        else if (currentArray[i][j] == dash){
          cout << "-";
        }
      }
      cout << endl;
    }
  }

  /*
  * General function for print out array with generation counts
  */
  void GameOfLife :: printEntireArray(){
    cout << generation << endl;
    for (int i = 0; i < arrayRows; ++i){
      for (int j = 0; j < arrayColumns; ++j){
        if (currentArray[i][j] == X){
          cout << "X";
        }
        else if (currentArray[i][j] == dash){
          cout << "-";
        }
      }
      cout << endl;
    }
    ++generation;
  }

  /*
  * Prints out the result grid to a output file
  */
  void GameOfLife :: printToFile(int ** arr){
    outputFileStream << generation << endl;
    if(outputFileStream.is_open()){
      for (int i = 1; i < arrayRows - 1; ++i){
        for (int j = 1; j < arrayColumns - 1; ++j){
          if(arr[i][j] == X){
            outputFileStream << "X";
          }
          else if (arr[i][j] == dash){
            outputFileStream << "-";
          }
        }
        outputFileStream << endl;
      }
    }
    ++generation;
  }
  /*
  * Output options that player can choose from
  * pause 3 seconds and proceed, wait for player to proceed, or print to output file
  */
  void GameOfLife :: pauseEnterOrOutput(){
    if ((output == 'p') || (output == 'P')){
      printArray(currentArray);
      cin.get(); // cannot really find a good way to pause 3 seconds and proceses
    }
    if ((output == 'e') || (output == 'E')){
      printArray(currentArray);
      cout << "Please press enter to process to nextArray generation." << endl;
      cin.get();
    }

    if ((output == 'o') || (output == 'O')){
      printToFile(currentArray);
    }
  }

  /*
  * The set up functions for running the game
  */
  void GameOfLife :: preparation(){
    choices();
    generateArrays();
    fillArrayInitial(originalArray);
    fillArraySides(originalArray);
    copyArray(originalArray, currentArray);
    checkIfEmpty(currentArray);
    pauseEnterOrOutput();
  }

  /*
  * The game of life checking for neighbors to calculate next generations or end the game
  */
  void GameOfLife :: playGame(){

    while (X_count != 0){
      for (int i = 1; i < arrayRows - 1; ++i){
        for (int j = 1; j < arrayColumns - 1; ++j){
          if ((currentArray[i - 1][j - 1])
          + (currentArray[i - 1][j])
          + (currentArray[i - 1][j + 1])
          + (currentArray[i][j - 1])
          + (currentArray[i][j + 1])
          + (currentArray[i + 1][j - 1])
          + (currentArray[i + 1][j])
          + (currentArray[i + 1][j + 1]) <= 1){

            nextArray[i][j] = dash;
          }

          if ((currentArray[i - 1][j - 1])
          + (currentArray[i - 1][j])
          + (currentArray[i - 1][j + 1])
          + (currentArray[i][j - 1])
          + (currentArray[i][j + 1])
          + (currentArray[i + 1][j - 1])
          + (currentArray[i + 1][j])
          + (currentArray[i + 1][j + 1]) == 2){

            nextArray[i][j] = currentArray[i][j];
          }

          if ((currentArray[i - 1][j - 1])
          + (currentArray[i - 1][j])
          + (currentArray[i - 1][j + 1])
          + (currentArray[i][j - 1])
          + (currentArray[i][j + 1])
          + (currentArray[i + 1][j - 1])
          + (currentArray[i + 1][j])
          + (currentArray[i + 1][j + 1]) == 3){

            nextArray[i][j] = X;
          }

          if ((currentArray[i - 1][j - 1])
          + (currentArray[i - 1][j])
          + (currentArray[i - 1][j + 1])
          + (currentArray[i][j - 1])
          + (currentArray[i][j + 1])
          + (currentArray[i + 1][j - 1])
          + (currentArray[i + 1][j])
          + (currentArray[i + 1][j + 1]) == 4){

            nextArray[i][j] = dash;
          }
        }
      }

      fillArraySides(nextArray);

      if (checkIfStable(currentArray, nextArray)){
        if ((output == 'o')||(output == 'O')){
          if (outputFileStream.is_open()){
            outputFileStream << "The grid is stable. Program end. " << endl;
          }
        }
        else {
          cout << "The grid is stable. Program end. " << endl;
        }
        break;
      }
      copyArray(nextArray, currentArray);

      checkIfEmpty(currentArray);

      pauseEnterOrOutput();

      if(X_count == 0){
        if ((output == 'o')||(output == 'O')){
        outputFileStream << "The grid is stable. Program end. " << endl;
        }
        else {
          cout << "The grid is stable. Program end. " << endl;
        }
      }
    }
  }
