//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.

template <class T> //This is the constructor
LinkedList<T>::LinkedList(){
  // Create the sentinel node
  dummyNode = new Node();
  // Point sentinel's prev and next to itself
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
  numItems = 0;
}

template <class T> //This is the destructor
LinkedList<T>::~LinkedList() {
  // Remove all other nodes in the list
  while(find(0)!=dummyNode){
	remove(0);
  }
  // Delete the sentinel node
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	return dummyNode;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it
  Node junkNode;
  return junkNode.data; //This is unitialized data

  // get the value at index i
  return find(i)->data;
}

template <class T> // Optional (for now)
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO; Get other methods completed first!
}

template <class T>
unsigned long LinkedList<T>::size(){
  //TODO
  return numItems; // should return numItems eventually
}
