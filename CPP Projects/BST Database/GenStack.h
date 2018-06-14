//  Yixing Zheng
//  2293298
//  zheng129@mail.chapman.edu
//  CPSC 350
//  Project 5

using namespace std;

/*
* The header file
*/
template <class T>
class GenStack{

public:
	GenStack(); // Constructor
	GenStack(int maxSize); // Overridden Constructor
	~GenStack(); // Destructor

	void push(T data); // push data into stack
	T pop(); // remove data from stack
	T peek(); // look at the value on top of the stack
	int isFull(); // check if the stack is full
	int isEmpty(); // check if the stack is empty

	int top; // the index for the value on top of the stack
	int max; // the max size of the stack
	T *myArray; // the generic array that the stack is based on
};

/*
* Constructor
*/
template <class T>
GenStack<T>::GenStack(){};

/*
* Overridden Constructor, defines the genstack with a size and a top
*/
template <class T>
GenStack<T>::GenStack(int maxSize){
	myArray = new T[maxSize];
	max = maxSize;
	top = -1;
}

/*
* Destructor, destroy everything in the world that ever exsited
* It is scary stuff, not funny at all
*/
template <class T>
GenStack<T>::~GenStack(){
	delete myArray;
}

/*
* Adds a value to the stack, double the size if full
*/
template <class T>
void GenStack<T>::push(T data){
	if (top == max - 1){
		T *temp1 = new T[max];

		for (int i = 0; i < max; ++i){
			temp1[i] = myArray[i];
		}

		myArray = new T[max * 2];

		for (int i = 0; i < max; ++i){
			myArray[i] = temp1[i];
		}

		max *= 2;
	}

	myArray[++top] = data;
}

/*
* Takes care of the useless value that is happend to be on top of the stack
*/
template <class T>
T GenStack<T>::pop(){
	if (top != -1){
		return myArray[top--];
	}

	else{
		return 0;
	}
}

/*
* Just take a very quick glance of what is on the top of the stack
*/
template <class T>
T GenStack<T>::peek(){
	return myArray[top];
}

/*
* Checks if the stack has eaten too much that it is full
*/
template <class T>
int GenStack<T>::isFull(){
	return (top == max-1);
}

/*
* Checks if the stack has been starving since long long time ago so it is empty
*/
template <class T>
int GenStack<T>::isEmpty(){
	return (top == -1);
}
