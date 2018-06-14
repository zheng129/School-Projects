//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 3

#ifndef MY_HEADER_FILE
#define MY_HEADER_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/*
* The header file
*/
template <class T>
class genstack {

public:
  genstack(int maxsize); // Constructor
  ~genstack(); // Destructor

  void push(T data); // push data into stack
  T pop(); // remove data from stack
  T peek(); // look at the value on top of the stack
  int isFull(); // check if the stack is full
  int isEmpty(); // check if the stack is empty
  bool pair(T a, T b); // check if two chars are a pair
  bool balanced(string line); // check if the file is balanced
  void choices(); // for users to choose weather check a file or not, if so, where is the file
  void checkFiles(); // helper function that opens and checks the file

  int lineNum; // keep track on the number of lines
  int charNum; // keep track on the number of chars
  int top; // the index for the value on top of the stack
  int max; // the max size of the stack
  char topElement; // the actually value of the top of the stack

  T *myArray; // the generic array that the stack is based on

private:

  std::string inputFileString; // input stream name
  std::ifstream inputFileStream; //input stream

};
#endif

/*
* Constructor, defines the genstack with a size and a top
*/
template <class T>
genstack<T> :: genstack(int maxsize){
  myArray = new T[maxsize];
  max = maxsize;
  top = -1;
}

/*
* Destructor, destroy everything in the world that ever exsited
* It is scary stuff, not funny at all
*/
template <class T>
genstack<T> :: ~genstack(){
  delete [] myArray;
}

/*
* Adds a value to the stack
*/
template <class T>
void genstack<T> :: push(T data){
  myArray[++top] = data;
}

/*
* Takes care of the useless value that is happend to be on top of the stack
*/
template <class T>
T genstack<T> :: pop(){
  return myArray[top--];
}

/*
* Just take a very quick glance of what is on the top of the stack
*/
template <class T>
T genstack<T> :: peek(){
  return myArray[top];
}

/*
* Checks if the stack has eaten too much that it is full
*/
template <class T>
int genstack<T> :: isFull(){
  return (top == max - 1);
}

/*
* Checks if the stack has been starving since long long time ago so it is empty
*/
template <class T>
int genstack<T> :: isEmpty(){
  return (top == -1);
}

/*
* Checks if the user is interested in select a file to check its delimiters
* If so, calls other funtions to check the file and provide answer to the user
*/
template <class T>
void genstack<T> :: choices(){
  string choice;

  do{
    cout << "Enter 'r' to check a file: " << endl;
    cout << "Or 'q' to quit the program " << endl;
    cin >> choice;

    if (choice == "r"){
      cout << "Please enter the full name of the file, including the .cpp at the end. " << endl;
      cin >> inputFileString;
      inputFileStream.open(inputFileString.c_str());

      checkFiles();

    }
    else if(choice == "q"){
      cout << "Program ended." << endl;
      exit(0);
    }
  }
  while ((choice != "q"));
}

/*
* Opens file and get everything as a string
* Then calls another function to do the actual work
*/
template <class T>
void genstack<T> :: checkFiles(){
  string line;
  if(inputFileStream.is_open()){

    stringstream strStream;
    strStream << inputFileStream.rdbuf();
    string str = strStream.str();

    if(!balanced(str)){
      cout << "Not balanced in line: " << lineNum << " at char " << charNum << "." << endl;
      if (topElement == '('){
        cout << "Line " << lineNum << ": expecting ')'" << endl;
      }
      else if (topElement == '{'){
        cout << "Line " << lineNum << ": expecting '}'" << endl;
      }
      else if (topElement == '['){
        cout << "Line " << lineNum << ": expecting ']'" << endl;
      }
      exit(0);
    }
    else{
      cout << "balanced." << endl;
    }
  }
  inputFileStream.close();
  lineNum = 0;
}

/*
* Helper function that checks if something and some other thing are a pair
* And most importanly telling the truth that if they are a pair
*/
template <class T>
bool genstack<T> :: pair(T a, T b){
  if(a == '(' && b == ')'){
    return true;
  }
  else if (a == '{' && b == '}'){
    return true;
  }
  else if (a == '[' && b == ']'){
    return true;
  }
  else{
    return false;
  }
}

/*
* Checks if the delimiters in the file is balanced
* Tracks number of lines, number of chars, and the element on top
* In order to find where is wrong
*/
template <class T>
bool genstack<T> :: balanced(string line){
  genstack<T> s(max);
  lineNum = 1;

  for (int i = 0; i < line.length(); ++i){
    ++charNum;
    if (line[i] == '\n'){
      ++lineNum;
      charNum = 0;
    }

    if(line[i] == '(' || line[i] == '{' || line[i] == '['){
      s.push(line[i]);
      topElement = s.peek();

      // Cannot really get this part figured out
      // Thinking I am not too far away from it yet it is just unattainable
      /*
      if(s.isFull()){
      genstack<T> temp(max);

      while(!s.isEmpty()){
      temp.push(s.peek());
      s.pop();
    }

    max *= 2;
    genstack<T> s(max);

    while(!temp.isEmpty()){
    s.push(temp.peek());
    temp.pop();
  }
}
*/
}
else if (line[i] == ')' || line[i] == '}' || line[i] == ']'){
  if(s.isEmpty() || !pair(s.peek(), line[i])){
    return false;
  }
  else{
    try{
      s.pop();
    }
    catch(exception e){
      cout << "Cannot pop, the stack is empty!" << endl;
    }
  }
}
}
return s.isEmpty();
}
