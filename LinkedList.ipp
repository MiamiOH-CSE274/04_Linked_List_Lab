//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
    numItems = 0;
    dummyNode = new Node();
    dummyNode -> data = NULL;
    dummyNode -> next = dummyNode;
    dummyNode -> prev = dummyNode;
}

template <class T>
LinkedList<T>::~LinkedList() {

  while (numItems > 0) {
        remove(0);
        }
  delete dummyNode;
  
  }


template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if (i > numItems)
    throw std::string ("List does not hold a Node at this value of i");
    
  if (i == numItems)
    return dummyNode;
    
  Node* finder = dummyNode -> next; //we are now at element i = 0
  unsigned long j = 0;
  while (j != i) {
    finder = finder -> next;
    j++;
  }
  return finder;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
    if (numItems < i)
      throw std::string ("Not enough elements to add at position i");

  Node* cur = find(i);
  Node* newNode = new Node();
  newNode -> data = x;
  newNode -> next = cur; //sets newNode's "next" to cur, moving cur up to i+1
  newNode -> prev = cur -> prev; //sets newNode's "previous" pointer to the "previous" pointer of cur.
  newNode -> prev -> next = newNode; //sets element i-1's "next" pointer to newNode's location
  newNode -> next -> prev = newNode; //sets element i+1's "prev" pointer to newNode's location
  numItems++;
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
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){

  return numItems;
}
