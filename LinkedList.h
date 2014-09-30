//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include <string>

#include "List.h"

template <class T>
class LinkedList : public List <T> 
{
private:
	struct Node
	{
		T data;
		struct Node* next;
		struct Node* prev;
	};

public:
	// See List.h for documentation of these methods
	// Return the number of items currently in the List
	virtual unsigned long size();

	// Get the value at index i, and return it.
	// If list does not contain at least i+1 items, throw a string exception
	virtual T get(unsigned long i);

	// Set the value at index i to x
	// If list does not contain at least i+1 items, throw a string exception
	virtual void set(unsigned long i, T x);

	// Add a new item, x, at position i. All items that were originally
	// at position i or higher get moved forward 1 to make room.
	// If list does not contain at least i items, throw a string exception
	virtual void add(unsigned long i, T x);

	// Remove the item at position i. All items that were originally
	// at position i+1 or higher get moved backwards 1 to fill the gap.
	// If list does not contain at least i+1 items, throw a string exception
	virtual void remove(unsigned long i);

	// Optional, but may be useful in the Shuffle project
	// Remove all items from src, and add them to the end of the current list, in the
	// same order that they started. So if the current list is {4, 1, 2} and src
	// is {3, 5}, the result should be that the current list is {4, 1, 2, 3, 5} and src is
	// empty
	// Note: This should be O(1) time. Use pointer manipulations to graft the lists together.
	// virtual void takeAll(LinkedList<T>& src);

	// Initialize all private member variables.
	// Be sure to create the dummy node using "new"
	LinkedList();
	// Delete any dynamically allocated memory. You will need to loop
	// through all your nodes, deleting them one at a time
	virtual ~LinkedList();

private:
	// Pointer to the dummy node.
	Node* dummyNode;

	// Return a pointer to item i.
	// Special cases: If i == numItems, return a pointer to the dummyNode
	// If i is an invalid number, throw a string exception
	Node* find(unsigned long i);

	// Number of items in the list
	unsigned long numItems;
};

// Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList()
{
	dummyNode = new LinkedList<T>::Node();
	dummyNode->next = dummyNode;
	dummyNode->prev = dummyNode;
	dummyNode->data = NULL;
	numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::Node *node = dummyNode;

	// start at end of list (will just be dummyNode if numItems == 0)
	node = node->prev;

	// loop through each element in list, from end to start
	for (unsigned int i = 0; i < numItems; i++) {
		node = node->prev;
		delete node->next;
	}

	// regardless of what numItems is, node == dummyNode here
	delete node;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i) 
{
	if (i > numItems) {
		throw std::string("error: index is larger than the size of the LinkedList");
	}

	LinkedList<T>::Node *ret;

	if (i == numItems) {
		// the ith element of a LinkedList of size i is always dummyNode
		ret = dummyNode;
	} else if (i < numItems / 2) {
		// start at beginning of list
		ret = dummyNode->next;

		for (unsigned long int k = 0; k < i; k++) {
			ret = ret->next;
		}
	} else {
		// start at end of list
		ret = dummyNode;

		for (unsigned long int k = numItems; k > i; k--) {
			ret = ret->prev;
		}
	}

	return ret;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x)
{
	LinkedList<T>::Node *node = find(i);
	node->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x)
{
	// create a new Node object
	LinkedList<T>::Node *new_node = new LinkedList<T>::Node();
	new_node->data = x;

	// get the Node that is already at position i
	LinkedList<T>::Node *old_node = find(i);

	// we are putting new_node in the place where old_node was, so the
	// previous Node for new_node is what the previous Node for old_node was
	new_node->prev = old_node->prev;

	// the next Node after new_node is the old_node that was there
	new_node->next = old_node;

	// the previous Node of old_node is new_node
	new_node->next->prev = new_node;

	// the next Node for the Node before new_node is new_node (only time this
	// Node is referenced)
	new_node->prev->next = new_node;

	numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i)
{
	if (numItems == 0) {
		throw std::string("error: no items left to remove");
	}

	// get the Node at position i
	LinkedList<T>::Node *node = find(i);

	// we just want to make the Node before node to point to the one after node
	// and the Node after node to point to the one before it
	node->prev->next = node->next;
	node->next->prev = node->prev;

	delete node;

	numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i)
{
	LinkedList<T>::Node *node = find(i);

	if (node == dummyNode) {
		throw std::string("error: index was too large in get()");
	} else {
		return node->data;
	}
}

template <class T>
unsigned long LinkedList<T>::size()
{
	return numItems;
}