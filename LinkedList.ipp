//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
	dummyNode= new Node;
	dummyNode->next=dummyNode;
	dummyNode->prev=dummyNode;
	numItems=0;
	
}

template <class T>
LinkedList<T>::~LinkedList() {
	while(numItems!=0)
	remove(0);
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  Node* temp;
  temp=dummyNode->next;
  for(unsigned long j=0;j<i;j++)
	temp=temp->next;
  return temp;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
	if (i < 0 ||i >= size())
		throw (std::string) "Can't set at that point";
	else{
  add(i,x);
  }
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	if (i < 0 ||i >= size())
		throw (std::string) "Can't add at that point";
	else{
	Node *temp= new Node;
	Node *before= find(i);
	temp->data=x;
	temp->prev= before->prev;
	temp->next= before;
	temp->next->prev=temp;
	temp->prev->next=temp;
	numItems++;
	}
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if (i < 0 ||i >= size())
		throw (std::string) "Can't remove at that point";
	else{
	Node* d=find(i);
	d->prev=d->next->prev;
	d->next=d->prev->next;
	numItems--;
	}
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	if (i < 0 ||i >= size()){
		throw (std::string) "Can't get the data at that point";}
	else{
	Node* temp=dummyNode;
	for(int j=0;j<<i;j++)
		temp=temp->next;
		//dummyNode=dummyNode->next;
	return temp->data;}
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
