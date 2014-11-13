//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List <T> {
 private:
  struct Node{
    T data;
    Node* next;
    Node* prev;
  };

 public:
  //See List.h for documentation of these methods
  //Return the number of items currently in the List
  virtual unsigned long size();

  //Get the value at index i, and return it.
  // If list does not contain at least i+1 items, throw a string exception
  virtual T get(unsigned long i);

  //Set the value at index i to x
  // If list does not contain at least i+1 items, throw a string exception
  virtual void set(unsigned long i, T x);

  //Add a new item, x, at position i. All items that were originally
  // at position i or higher get moved forward 1 to make room.
  // If list does not contain at least i items, throw a string exception
  virtual void add(unsigned long i, T x);

  //Remove the item at position i. All items that were originally
  // at position i+1 or higher get moved backwards 1 to fill the gap.
  // If list does not contain at least i+1 items, throw a string exception
  virtual void remove(unsigned long i);

  //Optional, but may be useful in the Shuffle project
  //Remove all items from src, and add them to the end of the current list, in the
  // same order that they started. So if the current list is {4, 1, 2} and src
  // is {3, 5}, the result should be that the current list is {4, 1, 2, 3, 5} and src is
  // empty
  //Note: This should be O(1) time. Use pointer manipulations to graft the lists together.
  //virtual void takeAll(LinkedList<T>& src);

  //Initialize all private member variables.
  // Be sure to create the dummy node using "new"
  LinkedList();
  //Delete any dynamically allocated memory. You will need to loop
  // through all your nodes, deleting them one at a time
  virtual ~LinkedList();

 private:
  //Pointer to the dummy node.
  Node* dummyNode;

  //Return a pointer to item i.
  //Special cases: If i == numItems, return a pointer to the dummyNode
  //If i is an invalid number, throw a string exception
  Node* find(unsigned long i);
  
  //Number of items in the list
  unsigned long numItems;
};

// Kyle Busdieker
// Prof. Bo Brinkman
// Date: November 13, 2014
// The skeleton code was created by Bo Brinkman and modified by Kyle Busdieker with help from other students, Open Data Structures textbook, and the internet.

//The LinkedList.ipp file
//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  
	dummyNode = new Node();
	dummyNode->next = dummyNode;  //These two lines compile exactly the same
	(*dummyNode).prev = dummyNode; //Same as the line above
	numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
 
	while(numItems > 0){
		remove(0);
	}
	delete dummyNode;
	dummyNode = NULL;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  
	Node* ret;

	if(i == numItems)
		return dummyNode;
	
	else if(i > numItems)
		throw std::string("Index is larger than number of items, in find()");
	
	else {
		ret = dummyNode->next;

		while(i > 0){
			ret = ret->next;
			i--;
		}
	}

	return ret;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){


	if(i == numItems)
		throw std::string("Index is larger than number of items, in set()");
	
	else {
		Node* updatedNode = find(i);
		updatedNode->data = x;
	}
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
 
	Node* nodeAtIndex = find(i);
	Node* newNode = new Node();

	newNode->data = x;

	newNode->next = nodeAtIndex;
	newNode->prev = nodeAtIndex->prev;

	nodeAtIndex->prev = newNode;
	newNode->prev->next = newNode;

	numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){

	Node* tempNode;
	if(i == numItems)
		throw std::string("Index is larger than number of items, in remove()");

	else {
		tempNode = find(i);
		tempNode->prev->next = tempNode->next;
		tempNode->next->prev = tempNode->prev;
		numItems--;
	}

	delete tempNode;
}

template <class T>
T LinkedList<T>::get(unsigned long i){

	Node* myNode = find(i);
	if(myNode == dummyNode)
		throw std::string("In get(), index was too large.");

	else
		return myNode->data;
}

template <class T>
unsigned long LinkedList<T>::size(){
  
  return numItems;
}

