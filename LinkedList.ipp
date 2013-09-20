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
  dummyNode.next = &dummyNode;
  dummyNode.prev = &dummyNode;
  numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList() {
  //TODO
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
  //TODO
  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  
  if(i>numItems)
    throw (std::string) "Linked list does not contain " + i + "items.
            Nothing added.";
  
  Node newItem = new Node();
  newItem.data = x;

  if(numItems==0){
    dummyNode.next = &newItem.data;
    dummyNode.prev = &newItem.data;
    newItem.next = &dummyNode.data;
    newItem.prev = &dummyNode.data;
    }
    
    Node* pointer = new Node();
    pointer.next = get(i);
    pointer.prev = get(i-1);

    
    numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  if(i<(numItems/2)){
  
  }
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
