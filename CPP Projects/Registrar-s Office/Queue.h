//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 4

#include "ListNode.h"

/*
* The header file of Queue
*/
template <class T>
class Queue{
  
public:
  ListNode<T> *front; // keep track on the front
  ListNode<T> *back; // keep track on the back
  unsigned int size; // keep track on the size

  /*
  * Constructor, defines the Queue with a front, a back, and a size
  */
  Queue(){
    size = 0;
    front = NULL;
    back = NULL;
  }

  /*
  * Destructor, does not do much for this time
  */
  ~Queue(){

  }

  /*
  * Adds a value to the Queue
  */
  void insert(T data){
    ListNode<T> *node = new ListNode<T>(data);

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
  * Removes a value from the Queue
  */
  T remove(){
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
  * Returns the value of the front
  */
  T getFront(){
    return front -> data;
  }

  /*
  * Returns the value of the back
  */
  T getBack(){
    return back -> data;
  }

  /*
  * Prints out all the data in the Queue
  */
  void printQueue(){
    ListNode<T> *current = front;

    while(true){
      if (current == NULL){
        break;
      }
      cout << current -> data << endl;
      current = current -> next;
    }
  }

  /*
  * Checks if the Queue is empty
  */
  int isEmpty(){
    return (size == 0);
  }

  /*
  * Checks the size of the Queue
  */
  unsigned int getSize(){
    return size;
  }
};
