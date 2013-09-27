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
  dummyNode -> next = dummyNode;
  dummyNode -> prev = dummyNode;
  dummyNode -> data = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
  Node* toDelete = dummyNode -> next;
  int numTimes = numItems;
  for (int i = 0; i < numTimes; i++) {
    remove(0);
  }
  delete dummyNode;

  }

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if (i >= numItems || i < 0) {
  return dummyNode;
  }
  if (i == size()-1) {
    return dummyNode->prev;
  }
  if (i == 0) {
  return dummyNode -> next;
  }
  Node* cur = dummyNode -> next;
  int currentNum = i;
  while (currentNum > 0) {
	cur = cur -> next;
	currentNum--;
	}
	
  return cur;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  if (i >= numItems || i < 0)
    throw std::string("That is an invalid index. Please choose a different one.");
  Node* cur = find(i);
  if (cur == dummyNode) {
    throw std::string("That index does not exist. Please choose a different one.");
  }
  cur -> data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  if (i > numItems || i < 0) {
    throw std::string("You can not add a node at that index. Please choose a different one.");
  }
  Node* cur = find(i);
  Node* temp = new Node();
  temp -> data = x;
  temp ->next = cur;
  temp -> prev = cur -> prev;
  temp -> prev -> next = temp;
  temp -> next -> prev = temp;
  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  if (numItems == 0) {
	throw std::string("You cannot remove an item from a list that does not contain any.");
  }
  if (i >= numItems || i < 0)
    throw std::string("That is an invalid index. Please choose a different one.");

  Node* cur = find(i);
  Node* previous = cur -> prev;
  Node* nextUp = cur -> next;
  previous->next = nextUp;
  nextUp -> prev = previous;
  numItems--;
  delete cur;
  
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  if (i >= numItems || i < 0)
    throw std::string("That is an invalid index. Please choose a different one.");
  if (find(i) == dummyNode) {
    throw std::string("That node does not exist, so you cannot get the value associated with it.");
  }
  Node* cur = dummyNode -> next;
  int currentNum = i;
  while (currentNum > 0) {
	cur = cur -> next;
	currentNum--;
	}
	return cur -> data;
	
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){


}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
