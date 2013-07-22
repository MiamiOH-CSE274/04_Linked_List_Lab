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
  numItems = 0;  
}

template <class T>
LinkedList<T>::~LinkedList() {
	for(int i=0;i<numItems;i++){
	  remove(0);
	}
	delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  if(i == (unsigned long)-1)
	  return dummyNode;
  
  if(i<0 || i>=numItems)
	  throw std::string("List does not contain i items.");
  Node* tmp = dummyNode->next;
  for(int j=0; j<numItems; j++){
	  if(j == i){
		  if(tmp == nullptr)
			  throw std::string("List does not contain i items.");
		  return tmp;
	  }
	  tmp = tmp->next;
  }
  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  Node* tmp = find(i);
  tmp->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  Node* tmp = find(i-1);
  Node* toAdd = new Node();
  toAdd->data = x;
  toAdd->next = tmp->next;
  tmp->next = toAdd;
  numItems++;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  Node* tmp = find(i-1);
  Node* toRemove = tmp->next;
  if(toRemove == nullptr)
	  throw std::string("No item to remove.");
  tmp->next = toRemove->next;
  delete toRemove;
  numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  Node* tmp = find(i);
  return tmp->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  
	for(int j=i;j<=len-1+i;j++){
		Node* tmp = find(i);
		target.add(t,tmp->data);
		remove(i);
		t++;
	}
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
