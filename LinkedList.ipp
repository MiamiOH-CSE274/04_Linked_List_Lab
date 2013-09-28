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
  dummyNode* = new dummyNode();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
}

template <class T>
LinkedList<T>::~LinkedList() {
  while(numItems > 0){	
		dummyNode->next = dummyNode->next->next;
		delete dummyNode->next->prev 
		dummyNode->next->prev = dummyNode;
		numItems--;	
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	if(i == (unsigned long)-1){
		return dummyNode;
		}
	else if(i < 0 || i > itemNums - 1){
		throw (std::string) "That is an invalid item to check";
	}
	else{
		Node* target = dummyNode;
		for(int index = 0; index < i; index++){
			target = target->next;
		}
		return target;
	}
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  find(i).data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
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
  return numItems;
}
