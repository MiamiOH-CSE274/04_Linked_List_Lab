//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
	numItems=0;
	next=dummyNode;
	prev=dummyNode;
}

template <class T>
LinkedList<T>::~LinkedList() {
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	if (i > numItems){throw std::cout << "ERROR: List does not contain such index. (find)" << std::endl; return;}
	if (i == numItems)
		return dummyNode;

	Node* p = dummyNode;
	for (int j = 0; j < i; j++)
		p = p.next;
	return p;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	if (i >= numItems){throw std::cout << "ERROR: List does not contain such index. (set)" << std::endl; return;}
	
	Node* a = find(i);
	a.data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	if (i >= numItems){throw std::cout << "ERROR: List does not contain such index. (add)" << std::endl; return;}
	
	Node newNode = new Node;
	newNode.data = x;
	
	Node *a = find(i);
	Node *u = a.next;
	a.next = newNode;
	u.prev = newNode;
	newNode.next = u;
	newNode.prev = a;

	++numItems;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (i >= numItems){throw std::cout << "ERROR: List does not contain such index. (remove)" << std::endl; return;}

	Node *a = find(i);
	Node *n = a.next;
	Node *p = a.prev;
	n.prev = a.prev;
	p.next = a.next;
	delete a;

	--numItems;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	Node junkNode;
	if (i >= numItems){throw std::cout << "ERROR: List does not contain such index. (get)" << std::endl; return junkNode.data;}
	
	Node *a = find(i);
	return a;
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
