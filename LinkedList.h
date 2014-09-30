//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List < T > {
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
* I worked alone on this assignment, but much of the code 
* is based on what we did in class and on the code
* examples in the book Open Data Structures by Pat Morin
*
* Caroline Danzi
* September 30, 2014
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
	// Set dummyNode's next and prev pointers
	// to point to itself
	dummyNode->next = dummyNode;
	dummyNode->prev = dummyNode;
	numItems = 0;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList() {
	// Get rid of the normal nodes - can reuse remove
	// since it deletes the node when finished
	while(numItems > 0){
		remove(0);
	}
	// Delete the dummyNode
	delete dummyNode;
	// Take care of the dangling pointer
	dummyNode = NULL;
}

// Returns a pointer to the node at i
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	// Can techically remove first case, but then it would take longer
	// since it would have to loop through the whole list
	if (i == numItems){
		return dummyNode;
	}
	else if (i > numItems){
		throw std::string("This index is larger than the number of items");
	}
	else{
		// Start at the node to the right of the dummyNode
		Node* returnVal = dummyNode->next;
		while (i > 0){
			// return the pointer to the next node
			returnVal = returnVal->next;
			i--;
		}
		return returnVal;
	}
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	// If i equaled the size of the list, the dummyNode
	// would be returned, which is bad - we do not want
	// to set the value of the dummyNode to anything.
	if (i == numItems){
		throw std::string("In set(), the index was too large.");
	}else{
		// Otherwise, find the node at i, and replace its data.
		Node* revisedNode = find(i);
		revisedNode->data = x;
	}
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	// Create a new Node using the data provided
	Node* newNode = new Node();
	newNode->data = x;
	// Find the node that is in the spot where
	// we want to add the new Node
	Node* displacedNode = find(i);

	// Set the pointers in the newNode to point to
	// the proper nodes in the list.
	// The next node after newNode should be the
	// one that was previously at that index.
	newNode->next = displacedNode;
	newNode->prev = displacedNode->prev;
	// Set the pointers of the nodes around newNode
	// to point to it.
	displacedNode->prev = newNode;
	newNode->prev->next = newNode;
	// Since we have added an item, increase the number of items.
	numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	// If i equals the number of items, there is no node
	// at index i, and thus nothing to remove. This also 
	// takes care of the case where there are no items in
	// the list. 
	if(i == numItems){
		throw std::string("Tried to remove an element beyond the length of the list, in remove().");
	}
	// Find the node to be removed
	Node* removedNode = find(i);
	// Set the pointers of the nodes around it to 
	// point to each other, bypassing the reomovedNode
	removedNode->prev->next = removedNode->next;
	removedNode->next->prev = removedNode->prev;
	// Delete the node at i and subtract one from numItems
	delete removedNode;
	numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	// If i is equal to numItems, find will return the dummyNode.
	// This is bad - dummyNode has no data to return.
	if (i == numItems){
		throw std::string("In get(), the index was larger than the number of items.");
	}else{
		// Otherwise, find the node at i and return its data.
		Node* myNode = find(i);
		return myNode->data;
	}
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
