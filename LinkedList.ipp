//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
	dummyNode = new LinkedList<T>::Node();
	dummyNode->next = dummyNode;
	dummyNode->prev = dummyNode;
	dummyNode->data = NULL;
	numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	LinkedList<T>::Node *node = dummyNode;

	while ((node = node->next) != dummyNode) {
		
	}
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i) 
{
	if (i > numItems) {
		throw std::string("error, element " + i + " is larger than the size of the LinkedList");
	}	

	LinkedList<T>::Node *p;

	if (i < numItems / 2) {
		// start at dummy
		p = dummyNode->next;

		for (unsigned long int k = 0; k < i; k++) {
			p = p->next;
		}
	} else {
		// start at end of list
		p = dummyNode;

		for (unsigned long int k = numItems; k > i; k--) {
			p = p->prev;
		}
	}

	return p;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	LinkedList<T>::Node *node = find(i);
	T ret = node->data;
	node->data = x;
	return ret;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	// create a new Node object
	LinkedList<T>::Node *new_node = new LinkedList<T>::Node();
	new_node->data = x;

	// get the Node that is already at position i
	LinkedList<T>::Node *old_node = find(i);

	// we are putting new_node in the place where old_node was, so the
	// previous Node for new_node is what the previous Node for old_node was
	new_node->prev = old_node->prev;

	// the next Node after new_node is the old_node that was there
	new_node->next = old_node;

	// the previous Node of old_node is new_node
	new_node->next->prev = new_node;

	// the next Node for the Node before new_node is new_node (only time this
	// Node is referenced)
	new_node->prev->next = new_node;

	numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	// get the Node at position i
	LinkedList<T>::Node *node = find(i);

	// we just want to make the Node before node to point to the one after node
	// and the Node after node to point to the one before it
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	delete node;

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
void LinkedList<T>::takeAll(LinkedList<T>& src)
{

}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
