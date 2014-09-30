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
	// same order that they started. So if the current list is {4, 1, 2} and src is {3, 5},
	// the result should be that the current list is {4, 1, 2, 3, 5} and src is empty
	//Note: This should be O(1) time. Use pointer manipulations to graft the lists together.
	virtual void takeAll(LinkedList<T>& src);

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

#include <string>

template <class T>
LinkedList<T>::LinkedList(){
	dummyNode=new Node();
	dummyNode->next=dummyNode;
	dummyNode->prev=dummyNode;
	numItems=0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (numItems > 0)
		remove(0);
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	if (i == numItems)
		return dummyNode;
	else if (i > numItems)
		throw std::cout << "ERROR: List does not contain such index. (find)" << std::endl;
	else {
		Node* a = dummyNode->next;
		while (i < 0) {
			a = a->next;
			i--;
		}
		return a;
	}
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	Node* a = find(i);
	if (a == dummyNode)
		throw std::string("In set(), index was too large.");
	else
		a->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	++numItems;
	if (i >= numItems)
		throw std::cout << "ERROR: List does not contain such index. (add)" << std::endl;

	Node* a = new Node();
	a->data = x;
	if (numItems == 0) {
		dummyNode->next = a;
		dummyNode->prev = a;
		a->next = dummyNode;
		a->prev = dummyNode;
	} else if (i == (numItems - 1)) {
		dummyNode->prev->next = a;
		a->prev = dummyNode->prev;
		dummyNode->prev = a;
		a->next = dummyNode;
	} else {
		Node *b = find(i);
		b->prev->next = a;
		a->prev = b->prev;
		b->prev = a;
		a->next = b;
	}
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (i >= numItems)
		throw std::cout << "ERROR: List does not contain such index. (remove)" << std::endl;
	if (numItems == 0)
		throw std::cout << "ERROR: List is empty. (remove)" << std::endl;
	else {
		Node *a = find(i);
		a->next->prev = a->prev;
		a->prev->next = a->next;
		delete a;
		--numItems;
	}
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	Node* a = find(i);
	if(a == dummyNode)
		throw std::cout << "ERROR: List does not contain such index. (get)" << std::endl;
	else
		return find(i)->data;
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}