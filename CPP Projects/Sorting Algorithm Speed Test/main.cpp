//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 6

#include <iostream>
#include "Sortings.h"

using namespace std;

// the main method of Sortings
int main(int argc, char** argv){
    Sortings sorting;

    if (argc == 2){
        if (sorting.setInputFile(argv[1])){ // checks if the file name is valid
            sorting.scanFile(); // if so, starts the program
        }

        else{
            cout << "\nFile does not exist." << endl;
        }
    }

    else{
        cout << "\nPlease provide a valid file name." << endl;
    }
    return 0;
}
