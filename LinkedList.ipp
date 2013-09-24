//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
//#define START_SIZE 10

template <class T>
LinkedList<T>::LinkedList(){
	
	Node* dummyNode = new Node();
	//Node* find = new Node[START_SIZE];
	numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList() {
	while (numItems > 0){
		remove(0);
	}
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  Node* p = new Node();
  if (i < (numItems/2)) {
	p = dummyNode -> next;
	for (int j = 0; (j < (int)i); j++)
		p = p -> next;
	}
	else {
		p = dummyNode;
		for (int j = numItems; j > (int)i; j--)
			p = p -> prev;
		}
	return (p);

}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  if (numItems < (int) i)
		throw (std::string) "List does not contain i items";
	Node* s = find(i);
	s->data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	
	Node* u = find(i);
	Node* temp = new Node();
	if (numItems < (int) i)
//		throw (std::string) "List does not contain i items";

	temp -> data = x;
	// THIS LINE BAD
	temp -> prev = u -> prev;
	temp -> next = u;
	temp -> next -> prev = temp;
	temp -> prev -> next = temp;
	numItems++;

	/*Node *u = find(i);
//	Node* temp = new Node();
//	temp -> data = x;
//	if (numItems == 0) {
//		u->prev = temp;
//	}
//	else
//		u->next = temp;
//	 u = temp;
//	 numItems++;

*/
	//	next = u;
	//	u = next[i];
	//next = u;
	//numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  Node *w = find(i);
  w -> prev -> next = w -> next;
  w -> next -> prev = w -> prev;
  delete w;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	if (numItems < (int) i)
		throw (std::string) "List does not contain i items";
	Node* f = find(i);
	return (f->data);
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
