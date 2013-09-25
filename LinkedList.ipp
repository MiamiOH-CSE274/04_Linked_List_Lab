//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
// Constructor
LinkedList<T>::LinkedList(){
  numItems = 0;
  dummyNode = new Node();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
}

template <class T>
// Destructor
LinkedList<T>::~LinkedList() {
// Deallocate memory
  while (numItems > 0) {
	remove(0);
	}
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	
// Test to make sure that i is a legal position in 
// the list, if not throw an exception
	if (i > numItems || i < 0) {
		throw std::string("Item not valid!");
	}
// Create a node pointer that can hold the item address
	Node* item;
	if (i < numItems/2) {
		item = dummyNode->next;
		for (unsigned long j = 0; j < i; j++) {
			item = item->next;
		} 
	 } else {
		item = dummyNode;
		for (unsigned long k = numItems; k > i; k--) {
			item = item->prev;
		}
	  }
	return item;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  // Test to make sure item i is in the list
	if (i > numItems || i < 0) {
		throw std::string ("Couldn't set the value x in node i!");
	}
	// I orginally had Node* cur = dummyNode + i;, Would this be okay to 
	// use if we didn't have the find method?
	Node* cur = find(i);
	cur->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
// Test to make sure that the placing the variable x
// in position i is legal
	if (i > numItems || i < 0) {
		throw std::string("Couldn't place item in the list!");
	}
// If i is a position in the list then go ahead and add item
	Node* temp = new Node();
	Node* cur = find(i);
	temp->next = cur;
	temp->prev = cur->prev;
	temp->data = x;
	temp->prev->next = temp;
	temp->next->prev = temp;
	numItems++;
	// Wasn't sure if we needed to delete the temp or not?
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (numItems == 0) {
		throw std::string ("No item to remove!");
	}
	// If the item is in the list then go ahead and remove it
	Node* temp = find(i);
	// Make sure to reset the list so that the previous
	// and next node to the one removed are up to date
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	// Since we allocated a new node we must delete it now that we are 
	// done with it.
	delete temp;
	numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	if (numItems == 0) {
		throw std::string ("No value to get!");
	}
	Node* temp = find(i);
	return temp->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
/*
  Node* temp = find(i);
  while (i < len) {
	for (int j = 0; j < len; j++) {
		
		numItems--;
		delete temp;	
	}
	Node* temp = find();
   }
   */
}
template <class T>
unsigned long LinkedList<T>::size(){
  // Return the number of items in the list by calling numItems
  return numItems;
}
