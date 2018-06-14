//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 3

A program that checks if the delimiters of a file is balanced

Submitted files:
main.cpp
genstack.h

test files:
B.txt // balanced
notB.txt // not balanced
B.cpp // somehow does not really work for the program
notB.cpp // same above

Known problem:
The program seems work fine with .txt files, but it does not work well with .cpp files.
The prompt for user choices prompts twice after a file is evaluated, and the result seems always to be balanced, which does not occur on checking .txt files.

The size of the stack cannot increase automatically when its full. I think I basically understand the idea of how to make a bigger stack, but I could not implement it.

Instruction for running program:
Compile main.cpp file by g++ through console, run the output file a.out or customize the name of the output file. Then follow the instruction inside the program.

Reference:

https://gist.github.com/mycodeschool/7207410

