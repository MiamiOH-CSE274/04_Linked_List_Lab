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
  Node* tempNode = dummyNode -> next;
  while(tempNode != dummyNode){
	tempNode = tempNode -> next;
	delete tempNode -> prev;
  }
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){

  LinkedList<T>::checkRange(i);
  Node* tempNode;

  if(i < numItems/2){
	tempNode = dummyNode -> next;
	for(int a = 0; a < i; a++)
		tempNode = tempNode -> next;

	return tempNode;

  }else{
	tempNode = dummyNode -> prev;
	for(int a = 0; a < i; a++)
		tempNode = dummyNode -> prev;

	return tempNode;
  }
  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  checkRange(i);

  Node* tempNode = find(i);

  tempNode -> data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  if(i < 0 || i > numItems) throw (std::string)"Array isn't large enough to add there!";
  if(i == 0 && numItems == 0){
	Node* tempNode = new Node();
	tempNode -> data = x;

	dummyNode -> next = tempNode;
	tempNode -> prev = dummyNode;
	tempNode -> next = dummyNode;
	dummyNode -> prev = tempNode;

	numItems++;
	std::cout<< "Added" << std::endl;
  return;
  }


  Node* tempNode = find(i);
  Node* newNode = new Node();
  newNode -> data = x;

  tempNode -> prev -> next = newNode;
  newNode -> prev = tempNode -> prev;
  newNode -> next = tempNode;
  tempNode -> prev = newNode;

  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  checkRange(i);

  Node* tempNode = find(i);

  tempNode -> prev -> next = tempNode -> next;
  tempNode -> next -> prev = tempNode -> prev;

  delete tempNode;

  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  
  Node* junkNode = find(i);
  return junkNode -> data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}

template <class T>
void LinkedList<T>::checkRange(unsigned long i){
	if(i < 0 || i > numItems){
		std::cout << "Exception!" << std::endl;
		std::cout << "Number of Items: " << numItems << std::endl;
		std::cout << "Integer i: " << i << std::endl;
		throw (std::string)"Array Out Of Bounds Exception";
	 }
}
