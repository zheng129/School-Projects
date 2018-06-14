//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 2

// the main method of the Game of Life
#include "GameOfLife.h" // including the header file 
#include <iostream>
#include <string>

int main(int argc, char** argv){

  GameOfLife myGame;

  myGame.preparation(); // the preparation of the game of Life

  myGame.playGame(); // runs the game

  return 0;
}
