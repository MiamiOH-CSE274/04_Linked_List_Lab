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
  
  dummyNode = new Node();
  dummyNode -> next = dummyNode;
  dummyNode -> prev = dummyNode;
  dummyNode -> data = NULL;

}

template <class T>
LinkedList<T>::~LinkedList() {

  while (numItems > 0)
	remove (0);
  delete dummyNode;

}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  
  Node* tempNode = dummyNode;

  //If i is out of the bounds of the size of the list,
  //the dummyNode (NULL) is returned and an error is thrown.
  if (i >= numItems || i < 0)
	throw (std::string) "Error: invalid input. Index out of bounds.";
  //If i equals 0, the first item in the list is returned.
  if (i == 0)
	tempNode = dummyNode -> next;
  //If i is any other number that hasn't been checked for yet,
  //the search will go through the list one item at a time until
  //it has reached the ith item. This item is then returned.
  else{
	tempNode = dummyNode -> next;
	for(int findCount = i; findCount > 0; findCount--){
	  tempNode = tempNode -> next;
	}
  }

  return tempNode;

}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  
  if (i >= numItems || i < 0)
	throw (std::string) "Error: invalid input. Index out of bounds.";
  
  Node* tempNode = find(i);
  if (tempNode == dummyNode)
	throw (std::string) "Error: Index does not exist.";
  
  tempNode -> data = x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  
  if (i >= numItems || i < 0)
	throw (std::string) "Error: invalid input. Item cannot be added at that index.";

  Node* insertPoint = find(i);
  Node* nodeToAdd = new Node();

  nodeToAdd -> data = x;
  nodeToAdd -> next = insertPoint;
  nodeToAdd -> prev = insertPoint -> prev;
  nodeToAdd -> prev -> next = nodeToAdd;
  nodeToAdd -> next -> prev = nodeToAdd;

  numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  
  if (i == 0)
	throw (std::string) "Error: invalid action. List has no items to delete.";
  if (i >= numItems || i < 0)
	throw (std::string) "Error: invalid action. Index out of bounds.";

  Node* nodeToDelete = find (i);
  nodeToDelete -> next -> prev = nodeToDelete -> prev;
  nodeToDelete -> prev -> next = nodeToDelete -> next;
  delete nodeToDelete;

  numItems--;

}

template <class T>
T LinkedList<T>::get(unsigned long i){
  
  if (i >= numItems || i < 0)
	throw (std::string) "Error: invalid action. Index out of bounds.";

  Node* nodeToFind = find (i);
  if (nodeToFind == dummyNode)
	throw (std::string) "Error: Index does not exist.";
  
  return (nodeToFind -> data);

}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  
  return numItems;

}
