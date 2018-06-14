//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include <iostream>

using namespace std;

/*
* The header file of the TreeNode
*/
template <class T>
class TreeNode{

public:

  T* data; // data
  int key; // key
  TreeNode<T> *left; // the left node
  TreeNode<T> *right; // the right node

  /*
  * Constructor, defines the TreeNode
  */
  TreeNode(){
    data = T();
    key = -1;
    left = NULL;
    right = NULL;
  }

  /*
  * Overridden Constructor, defines the TreeNode with a data, a left node, and a right node
  */
  TreeNode(T* d, int k){
    data = d;
    key = k;
    left = NULL;
    right = NULL;
  }

  /*
  * Destructor, who knows exactly what to do
  */
  ~TreeNode(){
    delete left;
    delete right;
    delete data;
  }
};
