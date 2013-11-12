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
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
}

template <class T>
LinkedList<T>::~LinkedList() {
  while(numItems>0){
	remove(0);
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i<0 || i>numItems){
	throw (std::string)"This item does not exist in the list";
  }
 
  if(i == (unsigned long)(numItems)){
	return dummyNode;
 }
 else{
  Node* foundNode = dummyNode->next;
  for(unsigned int j =0; j<i; j++){
	foundNode = foundNode->next;
 }
  return foundNode;
  }
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	find(i)->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  Node* original = find(i);
  Node* addedNode = new Node();
  addedNode->data = x;
  addedNode->next = original;
  addedNode->prev = original->prev;
  addedNode->prev->next = addedNode;
  addedNode->next->prev = addedNode;
  numItems++;
  
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  Node* removedNode = find(i);
  if(removedNode == dummyNode)
	throw (std::string)"The list is empty";
  removedNode->prev->next = removedNode->next;
  removedNode->next->prev = removedNode->prev;
  delete removedNode;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	return find(i)->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
	
	Node* back = find(i+len);
	Node* firstNodeOfSection = find(i);
	Node* front = firstNodeOfSection->prev;
	Node* lastNodeOfSection = find(i+len-1);
	Node* targetBack = target.find(t);
	Node* targetFront = targetBack->prev;
	firstNodeOfSection->prev = targetFront;
	back->prev = front;
	lastNodeOfSection->next = targetBack;
	front->next = back;
	targetFront->next = firstNodeOfSection;
	targetBack->prev = lastNodeOfSection;
	numItems-=len;
	target.numItems+=len;
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}

