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
	//TODO: Don't initialize this ... it only works because my test case has T being ints
	dummyNode->data = NULL; //capital is apparently important...
}//end constructor

//Delete dummyNode last. Iterate from beginning of list to the end. Each use of remove(0) will take the head node off of the LL and make the next node node-0. 
template <class T>
LinkedList<T>::~LinkedList() {
	Node* erase = dummyNode->next; //TODO: Unnecessary

	while(numItems > 0){
		remove(0);
	}

	delete dummyNode;
}//end destructor

//this must take constant time if the index requested is 0 or (numItems-1). Return dummyNode if i=numItems
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	if (i>=numItems || i<0)
		return dummyNode;
	if (i==size()-1)
		return dummyNode->prev;
	if (i==0)
		return dummyNode->next; //end special case testing
 
	Node* cur = dummyNode->next;

	while (i > 0) {
		cur = cur->next; //iterate down the line
		i -= 1;
	}

	return cur;
}//end find

//dependent on the "find(i)" function, must throw string if given an invalid index. Must take constant time if i=0 or i=(numItems-1).
template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	if(i<0 || i>=numItems)
		throw string("Invalid index given. Please choose one within the existing range.");

	Node* cur = find(i); //retrieves the address of the Node at the given index in the LL.

	if(cur==dummyNode) //this should never happen unless I screw up another method.
		throw string("Invalid index given. Please choose one within the existing range."); 

	cur->data = x; //sets data in retrieved Node to x.
}//end set

//must carefully set the links between adjacent nodes. Nodes at and above current position are moved up one.
template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	if (i>numItems || i<0)
		throw string("Invalid index given. Please choose one within the existing range.");

	Node* cur = find(i);
	Node* temp = new Node();
	temp->data = x; //sets data
	temp->next = cur; //moves existant node at position i up by one and links given node to it.
	temp->prev = cur->prev; //links given node to previous node.
	temp->prev->next = temp;
	cur->prev = temp; //links existant node to given one. All four links established.
	numItems += 1;
}

//remove node at given index, link previous and following nodes together.
template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (i>=numItems || i<0)
		throw string("Invalid index given. Please choose one within the existing range.");
    if (numItems==0)
		throw string("The list is empty. You cannot remove anything else.");

	Node* cur = find(i); //ah the swap paradigm from 174...good times...
	Node* previous = cur->prev;
	Node* upOne = cur->next;
	previous->next = upOne;
	upOne->prev = previous;
	numItems -= 1;
	delete cur;
}

//must be constant time for i=0 and i=(numItems-1)
template <class T>
T LinkedList<T>::get(unsigned long i){
	if (i>=numItems || i<0)
		throw string("That is an invalid index. Please choose a different one.");
	if (find(i)==dummyNode)
		throw string("That node does not exist, so you cannot get the value associated with it.");
	if(i==numItems-1)
		return dummyNode->prev->data;

	Node* cur = dummyNode->next; //Make sure to start at "index 0" and not at the dummyNode. This takes care of constant time for i=0;
	int remainingNodes = i;
	while (remainingNodes>0) {
		cur = cur->next; //Node* = Node*
		remainingNodes -= 1;
	}

	return cur->data;
}

template <class T>
void LinkedList<T>::takeAll(LinkedList<T>& src){//this is a pass by reference and not a pass by value, which is highly inconvenient for our purposes given, if the src list is deleted in
	Node* cur = find(numItems-1);// its own scope, the reference to it in our own LL will effectively go nowhere (I think).
	Node* beginning = src.find(0);
	Node* ending = src.find(src.size()-1);

	cur->next = beginning;
	beginning->prev = cur;
	ending->next = dummyNode;
	dummyNode->prev=ending;
	numItems += src.size();
}

template <class T>
unsigned long LinkedList<T>::size(){
	return numItems;
}
