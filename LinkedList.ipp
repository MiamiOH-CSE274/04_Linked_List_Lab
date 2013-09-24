//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  //Initialize variables
  dummyNode = new Node();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
  numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
  //De-allocate remaining list items
  while(numItems > 0){
		remove(0);
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i > numItems)
	throw std::string("That is an invalid input");
  unsigned long count = 0;
  Node* current = dummyNode->next;
  while(current != dummyNode) {
		if(count == i)
			return current;
		current = current->next;
		count++;
  }
  return dummyNode;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  Node* current = find(i);
  current->data = x;
}

template <class T>
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
void LinkedList<T>::remove(unsigned long i){
  if(numItems == 0)
	throw std::string("That is an invalid input");
  Node* current = find(i);
  current->prev->next = current->next;
  current->next->prev = current->prev;
  delete current;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //Check if we need to throw an exception
  if(i > numItems)
	throw std::string("That is an invalid input");
  Node* current = find(i);
  return current->data;
  
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
//Method to return the current size of the list
unsigned long LinkedList<T>::size(){
  return numItems;
}
