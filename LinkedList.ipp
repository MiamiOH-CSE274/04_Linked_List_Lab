//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
    Node dummyNodeR;
    dummyNodeR.next = &dummyNodeR;
    dummyNodeR.prev = &dummyNodeR;
    dummyNode = &dummyNodeR;
    numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList() {
  //TODO
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
    
    if(i>numItems)
        throw (std::string) "Linked list does not have enough items. Nothing to find.";
    Node* pointer;
    
    if(i<(numItems/2)){
        pointer = dummyNode;
        for(int location = 0; location<i; location++){
            pointer = pointer->next;
        }
    }
    
    else {
        pointer=dummyNode;
        for(unsigned long location = numItems; location>i; location--){
            pointer = pointer->prev;
        }
    }
    
    return pointer;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  
  if(i>numItems)
    throw (std::string) "Linked list does not have enough items. Nothing added";
  
  Node newItem;
  newItem.data = x;

  if(numItems==0){
    dummyNode->next = &newItem;
    dummyNode->prev = &newItem;
    newItem.next = dummyNode;
    newItem.prev = dummyNode;
    }
    
    Node* pointer = find(i);

    
    newItem.next = pointer;
    newItem.prev = pointer->prev;
    
    
    numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
    if (i>numItems) {
        throw (std::string)"Out of bounds exception.";
    }
    
    Node* info = find(i);
    Node toReturn;
    toReturn= *info;
  return toReturn.data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
