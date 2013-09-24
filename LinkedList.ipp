//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  //TODO
}

template <class T>
LinkedList<T>::~LinkedList() {
  //TODO
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  //TODO
  return NULL;
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
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it
  Node junkNode;
  return junkNode.data; //This is unitialized data
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  //TODO
  return 0;
}
