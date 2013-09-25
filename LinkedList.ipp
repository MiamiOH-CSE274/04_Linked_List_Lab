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
  while (numItems > 0) {
	remove(0);
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i) {
  if (i > numItems) {
	throw (std::string) "Error: Not enough items in list";
  }
  Node* p;
  if (i == numItems) {
	p = dummyNode;
	return p;
  }
  if (i < numItems / 2) {
	p = dummyNode -> next;
	for (int j = 0; j < i; j++) {
		p = p -> next;
	}
  } else {
	p = dummyNode -> prev;
	for (int j = numItems; j > i; j--) {
		p = p -> prev;
	}
  }
  return p;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x) {
  if (i > numItems) {
	throw (std::string) "Error: Not enough items in list";
  }
  Node* p = find(i);
  p -> data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x) {
  if (i > numItems) {
	throw (std::string) "Error: Not enough items in list";
  }
  Node* cur = find(i);
  Node* temp = new Node();
  temp -> data = x;
  temp -> next = cur;
  temp -> prev = cur -> prev;
  temp -> prev -> next = temp;
  temp -> next -> prev = temp;
  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i) {
  if (i > numItems) {
	throw (std::string) "Error: Not enough items in list";
  }
  Node* p = find(i);
  p -> prev -> next = p -> next;
  p -> next -> prev = p -> prev;
  delete p;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  if (i > numItems) {
	throw (std::string) "Error: Not enough items in list";
  }
  return find(i) -> data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size() {
  return numItems;
}