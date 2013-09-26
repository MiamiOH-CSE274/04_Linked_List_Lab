//You will need this so you can make a string to throw in
// remove
#include <string>

//Instance Variables
int numItems;
Node dummyNode;
Node* cur;

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  numItems = 0;
  dummyNode = new Node();
  dummyNode -> next = dummyNode;
  dummyNode -> prev = dummyNode;
  cur = dummyNode -> next;
}

template <class T>
LinkedList<T>::~LinkedList() {
  while(numItems > 0){
  remove(0);
  }
  delete dummyNode;
  delete numItems;
  delete cur;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i > numItems){
  throw (std::string)"The item does not exists, please enter another index";
  }
  if(i == numItems){
  return dummyNode;
  }

}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
 
  //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  Node* cur = find(i);
  Node* temp = new Node();
  
  //Below is making the new node.
  temp -> data = x;
  temp -> next = cur;
  temp -> prev = cur ->prev;
  
  //Below is adjusting old nodes to point in the correct direction
  temp -> prev -> next = temp;
  temp -> next -> prev = temp;

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
  //TODO
  return 0;
}
