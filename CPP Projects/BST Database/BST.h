//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

/*
* The header file for Double Linked List
*/
template <class T>
class BST{

private:
  TreeNode<T> *root; // the root of the tree
  int size; // the size of the tree

public:
  /*
  * Constructor, defines the BinarySearchTree with a root and a size
  */
  BST(){
    root = NULL;
    size = 0;
  }

  /*
  * Destructor, does not do much for this time
  */
  ~BST(){};

  /*
  * Adds a value to the back of the DoubleLinkedList
  */
  void insert(TreeNode<T> *node){

    if (root == NULL){
      root = node;
    }

    else{
      TreeNode<T> *current = root;
      TreeNode<T> *parent;

      while (true){
        parent = current;

        if (node -> key < current -> key){
          current = current -> left;

          if (current == NULL){
            parent->left = node;
            break;
          }
        }

        else{
          current = current -> right;

          if (current == NULL){
            parent -> right = node;
            break;
          }
        }
      }
    }
    size++;
  }

  /*
  * check if the key is inside the tree
  */
  bool isInTree(int k){
    if (root == NULL){
      return false;
    }

    TreeNode<T> *current = root;

    while (current -> key != k){
      if (k < current -> key){
        current = current -> left;
      }

      else{
        current = current -> right;
      }

      if (current == NULL){
        return false;
      }
    }
    return true;
  }

  /*
  * searches a key in the tree and returns its data
  */
  T* search(int k){
    if (isInTree(k)){
      TreeNode<T> *current = root;

      while (current -> key != k){
        if (k < current -> key){
          current = current -> left;
        }

        else{
          current = current -> right;
        }
      }

      return current -> data;
    }

    else{
      return NULL;
    }
  }

  /*
  * find the successor of the current TreeNode
  */
  TreeNode<T>* getSuccessor(TreeNode<T> *n){
    TreeNode<T> *successorParent = n;
    TreeNode<T> *successor = n;
    TreeNode<T> *current = n -> right;

    while (current != NULL){
      successorParent = successor;
      successor = current;
      current = current -> left;
    }

    if (successor != n -> right){
      successorParent -> left = successor -> right;
      successor -> right = n -> right;
    }
    return successor;
  }

  /*
  * delete a data from the tree
  */
  bool deleteNode(int k){
    if (root == NULL){
      return false;
    }

    TreeNode<T> *parent = root;
    TreeNode<T> *current = root;
    bool isLeft = true;

    while (current -> key != k){
      parent = current;

      if (k < current -> key){
        isLeft = true;
        current = current -> left;
      }

      else{
        isLeft = false;

        current = current -> right;
      }

      if (current == NULL){
        return false;
      }
    }

    if (current -> left == NULL && current -> right == NULL){

      if (current == root){
        root = NULL;
      }

      else if (isLeft){
        parent -> left = NULL;
      }

      else{
        parent -> right = NULL;
      }
    }

    else if (current -> right == NULL){

      if (current == root){
        root = current -> left;
      }

      else if (isLeft){
        parent -> left = current -> left;
      }

      else{
        parent -> right = current -> left;
      }
    }

    else if (current -> right == NULL){

      if (current == root){
        root = current -> right;
      }

      else if (isLeft){
        parent -> left = current -> right;
      }

      else{
        parent -> right = current -> right;
      }
    }

    else{
      TreeNode<T> *successor = getSuccessor(current);

      if (current == root){
        root = successor;
      }

      else if (isLeft){
        parent -> left = successor;
      }

      else{
        parent -> right = successor;
      }

      successor -> left = current -> left;
    }
    size--;
    return true;
  }

  /*
  * recursive method for printing out the tree
  */
  void print(TreeNode<T> *node){
    if (node == NULL){
      return;
    }

    print(node->left);
    cout << node->data << " | ";
    print(node->right);
  }

  /*
  * calls print method to print out the tree from the root
  */
  void printTree(){
    print(root);
  }

  /*
  * Checks the root of the BinarySearchTree
  */
  TreeNode<T>* getRoot(){
    return root;
  }

  /*
  * Checks the size of the BinarySearchTree
  */
  int getSize(){
    return size;
  }

  /*
  * Checks if the BinarySearchTree is empty
  */
  bool isEmpty(){
    return (size == 0);
  }
};
