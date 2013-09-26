//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.

template <class T> //This is the constructor
LinkedList<T>::LinkedList(){
  // Create the sentinel node
  dummyNode = new Node();
  // Point sentinel's prev and next to itself
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
  numItems = 0;
}

template <class T> //This is the destructor
LinkedList<T>::~LinkedList() {
  // Remove all other nodes in the list
  while(find(0)!=dummyNode){
	remove(0);
  }
  // Delete the sentinel node
  delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  // throw string exception if i is an invalid number
  if(i > numItems-1){
	throw std::string("Cannot find value: given index is invalid");
  }
  // returns a pointer to item i, UNLESS i==numItems 
  //      (if i==NumItems, return pointer to dummy node)
  else if(i==numItems)
  {
	return dummyNode;
  }
  else{
	// return pointer to item i
  }

  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  // throw string exception if list doesn't contain i items
  if(i > numItems - 1 || i<0){
	throw std::string("Cannot set value; list doesn't contain specific num items");
  }
  else{
	// find the node at i, then set it equal to x
  }
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  // throw string exception if list doesn't contain i items
  if(i > numItems - 1){
	throw std::string("Cannot add value; list doesn't contain specified num items");
  }
  // add a new item, x, at position i. (2 sections to check:
  // section 1: if item to insert is at the back of the list, or
  // section 2: item to insert has items already after it)
  else if(i==numItems){ // Item's at the back

	// Point the new node
	/*x->next=dummyNode;
	x->prev=find(i-1);
	find(i-1)->next=x;
	dummyNode->prev=x;*/

  }
  else{
	
  }
  numItems+=1;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  // throw a string exception if list doesn't contain i item, otherwise
  // get pointer for the node to remove
  // set node->prev->next = node->next
  // set node->next->prev = node->next
  // delete the node
  if(i > numItems - 1){
	throw std::string("Cannot remove value; list doesn't contain specified num items");
  }
  numItems-=1;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it

  // throw a string exception if list < i items, otherwise
  if(i > numItems -1){
	throw std::string("Cannot get value; list doesn't contained specified num items");
  }
  // get the value at index i
  Node junkNode;
	for(i=0; i<numItems; i++)
	{
		//junkNode.data=dummyNode->next;
	}

  
  return junkNode.data; //This is unitialized data
}

template <class T> // Optional (for now)
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO; Get other methods completed first!
}

template <class T>
unsigned long LinkedList<T>::size(){
  //TODO
  return numItems; // should return numItems eventually
}
