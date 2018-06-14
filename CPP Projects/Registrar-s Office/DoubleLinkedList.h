//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include <iostream>
#include "ListNode.h"

using namespace std;

/*
* The header file for Double Linked List
*/
template <class T>
class DoubleLinkedList{

public:
  ListNode *front; // keep track on the front
  ListNode *back; // keep track on the back
  unsigned int size; // keep track on the size

  DoubleLinkedList(); // Constructor
  ~DoubleLinkedList(); // Destructor

  void insertBack(T d); // add a value to the back
  T removeFront(); // delete a value from the front
  void remove(int key); // remove a node in the DoubleLinkedList by its value
  T getFront(); // check the value in front
  void printList(); // print out values
  int isEmpty(); // see if the DoubleLinkedList is empty
  unsigned int getSize(); // get the size of the DoubleLinkedList
};

/*
* Constructor, defines the DoubleLinkedList with a front, a back, and a size
*/
template <class T>
DoubleLinkedList :: DoubleLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

/*
* Destructor, does not do much for this time
*/
template <class T>
DoubleLinkedList :: ~DoubleLinkedList(){

}

/*
* Adds a value to the back of the DoubleLinkedList
*/
template <class T>
void insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if (size == 0){
    front = node;
  }
  else {
    back -> next = node;
    node -> prev = back;
  }
  back = node;
  ++size;
}

/*
* Removes a value from the front of the DoubleLinkedList
*/
template <class T>
T DoubleLinkedList :: removeFront(){
  if(!isEmpty()){

    ListNode<T> *oldFront = front;
    T oldData = oldFront -> data;

    if(front -> next == NULL){
      front = NULL;
      back = NULL;
    }
    else {
      front -> next -> prev = NULL;
      front = front -> next;
    }
    delete oldFront
    size--;
    return oldData
  }
  else {
    return T();
  }
}

/*
* Removes a value from the DoubleLinkedList based on its key's value
*/
template <class T>
void DoubleLinkedList :: remove(int key){
  int index = 0;
  ListNode *current = front;
  ListNode *previous = front;

  while (index != key){
    previous = current;
    current = current -> next;
    ++index;
  }
  previous -> next = current -> next;
  current -> next -> previous = previous;
  current -> next = NULL;
  current -> previous = NULL;
  current -> data = NULL;

  size--;
  delete current;
}

/*
* Returns the value of the front
*/
template <class T>
T DoubleLinkedList :: getFront(){
  return front -> data;
}

/*
* Prints out all the data in the DoubleLinkedList
*/
template <class T>
void DoubleLinkedList :: printList(){
  ListNode<T> *current = front;

  while(true){
    if (current -> next == NULL){
      break;
    }
    cout << current -> data << ", ";
    current = current -> next;
  }
}

/*
* Checks if the DoubleLinkedList is empty
*/
template <class T>
int DoubleLinkedList :: isEmpty(){
  return (size == 0);
}

/*
* Checks the size of the DoubleLinkedList
*/
template <class T>
unsigned int DoubleLinkedList :: getSize(){
  return size;
}
