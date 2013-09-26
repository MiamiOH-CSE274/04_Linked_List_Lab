//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
dummyNode=new Node();
 
 dummyNode->next=dummyNode;
 dummyNode->prev=dummyNode;
 
 numItems=0;
}

template <class T>
LinkedList<T>::~LinkedList() {
  
while(numItems>=1){

remove(0);}

delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
 
  if(i>numItems)
  throw (std::string) "not enough items in list";
  
  
 if(i==numItems){
 return dummyNode;}

  Node* foundNumber = dummyNode->next;
  int j=0;
  while(j<i){
  foundNumber = foundNumber->next;
  j++;
}
  
  return foundNumber;
  
  

}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){

  if(i>numItems )
  throw (std::string) "not enough items in list";

find(i)->data=x;

}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
if(i>numItems )
 throw (std::string) "not enough items in list";
 
 


Node* cur= find(i);
Node* temp= new Node();
temp->data=x;
temp->next=cur;
temp->prev=cur->prev;
temp->prev->next=temp;
temp->next->prev=temp;
numItems=numItems+1;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){

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
  //TODO
  return 0;
}
