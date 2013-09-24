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
//	while (numItems > 0){
//		remove(0);
//	}
//	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	Node* p;
	
	if (i > numItems)
		throw (std::string) "Invalid i (find)";
	if (i == numItems)
		return dummyNode;
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

//std::cout << "FIND" << p << std::endl;
	
	return (p);

//return dummyNode;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
 /* if (numItems < (int) i)
		throw (std::string) "List does not contain i items";
		*/
	Node* s = find(i);
//	T y = s->data;
//	s->data = x;

//	std::cout << "SET" << s << std::endl;
	
	s->data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
//numItems++;
//std::cout << "i" << i << std::endl;
//std::cout << "X" << x << std::endl;
// Freezes when find(i), updating numItems, and temp prev next and temp next prev

	Node* u = find(i);

//	std::cout << "ADD" << u->data << std::endl;

	Node* temp = new Node();

	if (i > numItems)
		throw (std::string) "List does not contain i items(add)";

	temp -> data = x;
//	temp -> next = u;
//	temp -> prev = u -> prev;
//	temp -> prev -> next = temp;
//	temp -> next -> prev = temp;


	temp -> next = u;
	temp -> prev = u -> prev;
	temp -> prev -> next = temp;
	temp -> next -> prev = temp;
	

	numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
//numItems--;
	if (numItems == 0)
		throw (std::string) "List is already empty! (remove)";

  Node* w = find(i);
//  std::cout << "REMOVE" << w << std::endl;
  w -> prev -> next = w -> next;
  w -> next -> prev = w -> prev;
 // delete w;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	if (numItems < (int) i)
		throw (std::string) "List does not contain i items";
	Node* f = find(i);
	return (f -> data);
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
