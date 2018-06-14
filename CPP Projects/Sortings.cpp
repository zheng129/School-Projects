//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 6

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Sortings.h"

using namespace std;

/*
* Constructor
*/
Sortings :: Sortings(){};

/*
* Destructor, delete arrays and return memory
*/
Sortings :: ~Sortings(){
  delete [] quickSortArray;
  delete [] insertSortArray;
  delete [] heapSortArray;
}

/*
* checks if the name of the file from input is valid
*/
bool Sortings :: setInputFile(string name){
	ifstream fileTest;
	fileTest.open(name.c_str());

	if (fileTest.is_open()){
		fileTest.close();
		fileName = name;

		return true;
	}

	else{
		return false;
	}
}

/*
* gets the contents from the file for the program to operate
*/
void Sortings :: scanFile(){
    ifstream inputFile;
    inputFile.open(fileName.c_str());

    string elementCountsStr;
    string line;
    double value;
    int lineNumber = 1;

    getline(inputFile, elementCountsStr);

    try{
        elementCounts = stoi(elementCountsStr);
    }

    catch(exception e){
        cout << "\nIncorrect format on line: " << lineNumber << endl;
        return;
    }

    quickSortArray = new double[elementCounts];
    insertSortArray = new double[elementCounts];
    heapSortArray = new double[elementCounts];

    for (int i = 0; i < elementCounts; ++i){
        lineNumber++;
        getline(inputFile, line);

        try{
            value = stod(line);
        }

        catch(exception e){
            cout << "\nIncorrect format on line: " << lineNumber << endl;
            return;
        }

        quickSortArray[i] = value;
        insertSortArray[i] = value;
        heapSortArray[i] = value;
    }

    inputFile.close();

    sortAll();
}

/*
* the quickSort algorithm
*/
void Sortings :: quickSort(double array[], int left, int right){
    int index = partition(array, left, right);

    if (left < index - 1){
        quickSort(array, left, index - 1);
    }

    if (index < right){
        quickSort(array, index, right);
    }
}

/*
* helper method for quickSort algorithm
*/
int Sortings :: partition(double array[], int left, int right){
    int pivot = array[ (left + right) / 2];

    while (left <= right){
        while (array[left] < pivot){
            left++;
        }

        while (array[right] > pivot){
            right--;
        }

        if (left <= right){
            swap(array, left, right);
            left++;
            right--;
        }
    }
    return left;
}

/*
* the insertionSort algorithm
*/
void Sortings :: insertionSort(double array[]){
    for (int j = 1; j < elementCounts; ++j){
        double temp = array[j];
        int k = j;

        while (k > 0 && array[k - 1] >= temp){
            array[k] = array[k - 1];
            --k;
        }
        array[k] = temp;
    }
}

/*
* helper method for heapSort algorithm
*/
void Sortings :: heapify(double array[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest]){
        largest = l;
      }

    if (r < n && array[r] > array[largest]){
        largest = r;
      }

    if (largest != i){
        swap(array, i, largest);
        heapify(array, n, largest);
    }
}

/*
* the heapSort algorithm
*/
void Sortings :: heapSort(double array[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--){
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}

/*
* runs each algorithm and times them
*/
void Sortings :: sortAll(){
    clock_t timeStart;
    clock_t timeEnd;

    cout << "\nSorting in process:\n";

    timeStart = clock();
    quickSort(quickSortArray, 0, elementCounts - 1);
    timeEnd = clock();

    printf("\nQuickSort took %.2fms to sort %d numbers.\n", ( float( timeEnd - timeStart ) / CLOCKS_PER_SEC ) * 1000, elementCounts);

    timeStart = clock();
    insertionSort(insertSortArray);
    timeEnd = clock();

    printf("\nInsertionSort took %.2fms to sort %d numbers.\n", ( float( timeEnd - timeStart ) / CLOCKS_PER_SEC ) * 1000, elementCounts);

    timeStart = clock();
    heapSort(heapSortArray, sizeof(heapSortArray)/sizeof(heapSortArray[0]));
    timeEnd = clock();

    printf("\nHeapSort took %.3fms to sort %d numbers.\n\n", ( float( timeEnd - timeStart ) / CLOCKS_PER_SEC ) * 1000, elementCounts);
}

/*
* checks if the array is sorted
*/
bool Sortings :: isSorted(double array[]){
    for (int i = 0; i < elementCounts - 1; ++i){
        if (array[i] > array[i + 1]){
            return false;
        }
    }
    return true;
}

/*
* swaps two elements in an array
*/
void Sortings :: swap(double array[], int a, int b){
    double temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/*
* gets the name of the file
*/
string Sortings :: getFileName(){
    return fileName;
}
