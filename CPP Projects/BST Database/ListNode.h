//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>

using namespace std;

/*
* The header file of the ListNode
*/
template <class T>
class ListNode{
public:
	T data;
	ListNode<T> *next; // the next node
	ListNode<T> *prev; // the previous node

	/*
	* Constructor, defines the ListNode
	*/
	ListNode(){};

	/*
	* Overridden Constructor, defines the ListNode with a data, a next node, and a previous node
	*/
	ListNode(T d){
		data = d;
		next = NULL;
		prev = NULL;
	}

	/*
	* Destructor, who knows exactly what to do
	*/
	~ListNode(){
		if (next != NULL){
			next = NULL;
			prev = NULL;

			delete next;
			delete prev;
		}
	}
};
