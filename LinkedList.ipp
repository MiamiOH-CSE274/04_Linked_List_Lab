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
  dummyNode->next=dummyNode;
  dummyNode->prev=dummyNode;
  int numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while(dummyNode->next != dummyNode){
		delete dummyNode->next;
	}
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	Node* result = dummyNode;
	int j = -1;
	while(j!=i){
		result = result->next;
		j++;
		}
	return result;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  find(i)->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  Node* temp = new Node();
  temp->data = x;
  Node* bump = find(i);
  temp->next = bump;
  temp->prev = bump->prev;
  bump->prev = temp;
  temp->prev->next = temp;
  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  Node* toBeRemoved = find(i);
  toBeRemoved->prev->next = toBeRemoved->next;
  toBeRemoved->next->prev = toBeRemoved->prev;
  delete toBeRemoved;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  return find(i)->data; //This is unitialized data
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
