//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
//Constructor
LinkedList<T>::LinkedList(){
  //Initialize variables
  dummyNode = new Node();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
  numItems = 0;
}

template <class T>
//Destructor
LinkedList<T>::~LinkedList() {
  //De-allocate remaining list items
  while(numItems > 0){
		remove(0);
  }
  delete dummyNode;
}

template <class T>
//Method to find the given index in the Linked list and return the pointer to that index
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  //Check if the index inputted is invalid
  if(i > numItems || i < 0)
  	throw std::string("That is an invalid input");
  //Originally had the find() implemented from the in-class example, changed it to the example given from the book
  Node* current;
  if(i < numItems/2) {
		current = dummyNode->next;
		for(unsigned long j = 0; j < i; j++)
			current = current->next;
  }
  else {
		current = dummyNode;
		for(unsigned long j = numItems; j > i; j--)
			current = current->prev;
  }
  return current;
}

template <class T>
//Method to set the data value of a node at a specific index
void LinkedList<T>::set(unsigned long i, T x){
  Node* current = find(i);
  current->data = x;
}

template <class T>
//Method to add a node to the list at the given index
void LinkedList<T>::add(unsigned long i, T x){
  //Based on code we were given in class
  Node* current = find(i);
  Node* temp = new Node();
  temp->data = x;
  temp->next = current;
  temp->prev = current->prev;
  temp->prev->next = temp;
  temp->next->prev = temp;
  numItems++;
}

template <class T>
//Method to remove a node at a specific index from the list
void LinkedList<T>::remove(unsigned long i){
  //Check if the list is empty
  if(numItems == 0)
	throw std::string("That is an invalid input");
  Node* current = find(i);
  current->prev->next = current->next;
  current->next->prev = current->prev;
  delete current;
  numItems--;
}

template <class T>
//Method to get the data from a node at a specific index
T LinkedList<T>::get(unsigned long i){
  Node* current = find(i);
  return current->data;
  
}

template <class T>
//Method to splice the list into another target list
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  for(unsigned long j = 0; j < len; j++){
		target.add(t,get(i));
		remove(i);
		t++;
  }
}

template <class T>
//Method to return the current size of the list
unsigned long LinkedList<T>::size(){
  return numItems;
}
