//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  dummyNode = new Node();
  dummyNode -> next = dummyNode;
  dummyNode -> prev = dummyNode;
  numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
  while(numItems > 0){
  remove(0);
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i > numItems || i < 0){
  throw (std::string)"The item does not exists, please enter another index";
  }
  if(i == numItems){
  return dummyNode;
  }

  //below it is indexing to find index i.
  Node* cur = dummyNode ->next;
  int count = 0;
  while(count != i){
	cur = cur -> next;
	count++;
  }
  return cur;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
 find(i)->data = x;
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
  if(numItems == 0){
  throw (std::string)"The list is empty cannot remove";
  }
  if(i > numItems){
  throw (std::string)"The item does not exists, please enter another index";
  }
  Node* cur = find(i);
  
  cur -> prev -> next = cur -> next;
  cur -> next -> prev = cur -> prev;
  delete cur;
  numItems--; 
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  return find(i)->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
