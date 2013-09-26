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
  // Point sentinel's prev and next to itself
}

template <class T> //This is the destructor
LinkedList<T>::~LinkedList() {
  // Remove all other nodes in the list
  // Delete the sentinel node
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  // throw string exception if i is an invalid number
  // returns a pointer to item i, UNLESS i==numItems 
  //      (if i==NumItems, return pointer to dummy node)

  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  // throw string exception if list doesn't contain i items
  // set index i to x
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  // throw string exception if list doesn't contain i items
  // add a new item, x, at position i. (2 sections to check:
  // section 1: if item to insert is at the back of the list, or
  // section 2: item to insert has items already after it)
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  // throw a string exception if list doesn't contain i item, otherwise
  // get pointer for the node to remove
  // set node->prev->next = node->next
  // set node->next->prev = node->next
  // delete the node
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it

  // throw a string exception if list < i items, otherwise
  // get the value at index i

  Node junkNode;
  return junkNode.data; //This is unitialized data
}

template <class T> // Optional (for now)
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO; Get other methods completed first!
}

template <class T>
unsigned long LinkedList<T>::size(){
  //TODO
  return 0; // should return numItems eventually
}
