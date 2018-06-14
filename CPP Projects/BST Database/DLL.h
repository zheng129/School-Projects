//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>
#include "ListNode.h"

using namespace std;

/*
* The header file for Double Linked List
*/
template <class T>
class DLL{
public:
  ListNode<T> *front; // keep track on the front
  ListNode<T> *back; // keep track on the back
  unsigned int size; // keep track on the size

  /*
  * Constructor, defines the DoubleLinkedList with a front, a back, and a size
  */
  DLL(){
    size = 0;
    front = NULL;
    back = NULL;
  }

  /*
  * Destructor, does not do much for this time
  */
  ~DLL(){
    delete front;
    delete back;
  }

  /*
  * Adds a value to the back of the DoubleLinkedList
  */
  void insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if (size == 0){
      front = node;
    }

    else{
      back -> next = node;
      node -> prev = back;
    }
    back = node;
    ++size;
  }

  /*
  * Removes a value from the front of the DoubleLinkedList
  */
  T removeFront(){
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
      delete oldFront;
      size--;
      return oldData;
    }
    else {
      return T();
    }
  }

  /*
  * Removes a value from the DoubleLinkedList based on its key's value
  */
  void removeAt(int pos){
    int index = 0;
    ListNode<T> *current = front;
    ListNode<T> *previous = front;

    while (index != pos){
      previous = current;
      current = current -> next;
      ++index;
    }

    previous -> next = current -> next;
    current -> next -> prev = previous;
    current -> next = NULL;
    current -> prev = NULL;
    size--;
    delete current;
  }

  /*
  * Returns the value of the front
  */
  T getFront(){
    return front -> data;
  }

  /*
  * Prints out all the data in the DoubleLinkedList
  */
  void printList(){
    if (front != NULL){
      ListNode<T> *current = front;

      while (true){
        if (current == NULL){
          break;
        }

        cout << current -> data << ", ";
        current = current -> next;
      }
    }

    else{
      cout << "None";
    }
  }

  /*
  * Checks the size of the DoubleLinkedList
  */
  unsigned int getSize(){
    return size;
  }

  /*
  * Checks if the DoubleLinkedList is empty
  */
  bool isEmpty(){
    return (size == 0);
  }
};
