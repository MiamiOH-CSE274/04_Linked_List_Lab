//You will need this so you can make a string to throw in
// remove
#include <string>
using std::string;

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
	numItems = 0;
    dummyNode = new Node();
	dummyNode->next = dummyNode;
	dummyNode->prev = dummyNode;
	dummyNode->data = NULL; //capital is apparently important...
}

//Delete dummyNode last. Iterate from beginning of list to the end. Each use of remove(0) will take the head node off of the LL and make the next node node-0. 
template <class T>
LinkedList<T>::~LinkedList() {
	/*while(numItems > 0){
		remove(0)
	}

	delete dummyNode;
	*/
}

//this must take constant time if the index requested is 0 or (numItems-1).
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  //TODO
  return NULL; //delete this
}

//dependent on the "find(i)" function, must throw string if given an invalid index. Must take constant time if i=0 or i=(numItems-1).
template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	if(i<0 || i>=numItems)
		throw string("Invalid index given. Please choose one within the existing range.");
	Node* cur = find(i); //retrieves the address of the Node at the given index in the LL.

	if(cur==dummyNode) //this should never happen unless I screw up another method.
		throw string("Invalid index given. Please choose one within the existing range."); 

	cur->data = x; //sets data in retrieved Node to x.
  //TODO
}

//must carefully set the links between adjacent nodes. Nodes at and above current position are moved up one.
template <class T>
void LinkedList<T>::add(unsigned long i, T x){
    if (i>numItems || i<0) {
    throw string("Invalid index given. Please choose one within the existing range.");
  }
  Node* cur = find(i);
  Node* temp = new Node();
  temp->data = x; //sets data
  temp->next = cur; //moves existant node at position i up by one and links given node to it.
  temp->prev->next = temp; //links previous node to given node.
  temp->next->prev = temp; //links existant node to given one. All four links established.
  numItems += 1;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  //TODO -- The code that is here is a useless stub, you probably
  // want to delete it
  return NULL;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  //TODO
  return 0;
}
