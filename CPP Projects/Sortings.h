//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 6

// the header file of the three sorting algorithms
using namespace std;

class Sortings{

public:
  Sortings(); // Constructor
  ~Sortings(); // Destructor

  bool setInputFile(string name); // checks if the name of file is valid
  void scanFile(); // if the name is valid, scan the contents for the program

  void quickSort(double array[], int left, int right); // the quickSort algorithm
  int partition(double array[], int left, int right); // helper method for quickSort algorithm

  void insertionSort(double array[]); // the insertionSort algorithm

  void heapSort(double array[], int n); // the heapSort algorithm
  void heapify(double arrar[], int n, int i); // helper method for heapSort algorithm

  void sortAll(); // sorts in all three algorithms and times each algorithm
  bool isSorted(double array[]); // checks if the arrays are sorted
  void swap(double array[], int a, int b); // swaps two integers

  string getFileName(); // gets the name of the file

private:
  string fileName; // file's name
  int elementCounts; // the number of elements in the array

  double *quickSortArray; // the array for quickSort
  double *insertSortArray; // the array for insertionSort
  double *heapSortArray; // the array for heapSort

};
