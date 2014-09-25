//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List <T> {
	// Private class inside the LinkedList class
	// struct - only holds data members, no methods
	// "Node class"
	// only accessible through the LinkedList class
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
	// Constructor
	LinkedList();
	//Delete any dynamically allocated memory. You will need to loop
	// through all your nodes, deleting them one at a time
	// Destructor
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

/*
* Originality statement!
*/

//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.

// Constructor
template <class T>
LinkedList<T>::LinkedList(){
	// Create a node for the dummyNode
	dummyNode = new Node();
	dummyNode->next = dummyNode;
	dummyNode->prev = dummyNode;
	numItems = 0;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList() {
	//TODO
}

// Returns a pointer to the node at i
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	// Can techically remove first case, but then it would take longer
	// since it would have to loop through the whole list
	// First case in here for speed
	if(i == numItems){
		return dummyNode;
	}else if(i > numItems){
		throw std::string("This index is larger than the number of items, in find()");
	}else{
		// Start at the node to the right of the dummyNode
		Node* returnVal = dummyNode->next;
		while(i > 0){
			// return the pointer to the next node
			returnVal = returnVal->next;
			i--;
		}
		return returnVal;
	}
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	//TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	//TODO
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	//TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	Node* myNode = find(i);
	if(myNode == dummyNode){
		// If i is equal to numItems, find will return the dummyNode
		// If i was larger than numItems, the exception would have been
		// thrown in find(i)
		throw std::string("In get(), the index was too large.");
	}else{
		return myNode->data;
	}
}

template <class T>
unsigned long LinkedList<T>::size(){
	//TODO
	return 0;
}
