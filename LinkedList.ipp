//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
#define START_SIZE 10

template <class T>
LinkedList<T>::LinkedList(){
	
	Node* dummyNode = new Node();
	//Node* find = new Node[START_SIZE];
	numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList() {
	while (numItems > 0)
		remove(0);
	delete dummyNode;
	//delete prev;
 // delete dummyNode[];
 // delete data[];
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
	Node* u = find(i);
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = u;
	temp -> prev = u -> prev;
	temp -> prev -> next = temp;
	temp -> next -> prev = temp;
//	Node *u = new Node[x];
//	Node* next;
	//Node* tail;
	//Node* find;
//	if (numItems == 0) {
//	Node* prev = u;
//	}
	//else
	//	Node* tail = u;
	// tail->next = u
	//	next = u;
	//	u = next[i];
	//next = u;
	//numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
//	Node dummyNode;
//	return dummyNode.data;
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
  return numItems;
}
