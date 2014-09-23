//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
	
}

template <class T>
LinkedList<T>::~LinkedList() {
	
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	

	return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	
	
	Node junkNode;
	return junkNode.data; //This is unitialized data
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
	
}

template <class T>
unsigned long LinkedList<T>::size(){
	
	
	return 0;
}
