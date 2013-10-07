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
    dummyNode->next = dummyNode;
    dummyNode->prev = dummyNode;
    numItems = 0;

}

template <class T>
LinkedList<T>::~LinkedList() {
    while (numItems!=0) {
        remove(0);
    }
    delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
   if (i==numItems) {
      return dummyNode;
    }
    if(i>numItems)
        throw (std::string) "Linked list does not have enough items. Nothing to find.";

    Node* pointer = new Node();
    pointer = dummyNode;
    if(i!=numItems-1){
        pointer = dummyNode->next;
        for (unsigned long location = 0; location<i; location++) {
            pointer = pointer->next;
        }
        
    }
    
    else{
        pointer = dummyNode->prev;
    }
    
    return pointer;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
    Node* nodeToChange = find(i);
    nodeToChange->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
  
  if(i>numItems)
    throw (std::string) "Linked list does not have enough items. Nothing added";
  
    Node* itemToMove = find(i);
    Node* newItem = new Node();
    newItem->data = x;
    
    newItem->next = itemToMove;
    newItem->prev = itemToMove->prev;
    itemToMove->prev = newItem;
    newItem->prev->next = newItem;

    numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i){
    if(i>numItems)
        throw (std::string) "Linked list does not have enough items. Nothing removed";
    if(numItems==0)
        throw (std::string) "Linked list does not have any items. Nothing removed";
    
    Node* toRemove = find(i);
    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;
    delete toRemove;
    numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
    
    Node* pointer = find(i);

  return pointer->data;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
    
    Node* startNewList = find(i);
    Node* endNewList = find(i+len-1);
    Node* placeToMerge = (target.find(t));
    
    startNewList->prev->next= endNewList->next;
    endNewList->next->prev = startNewList->prev;
    
    startNewList->prev = placeToMerge->prev;
    endNewList->next = placeToMerge;
    placeToMerge->prev->next = startNewList;
    placeToMerge->prev = endNewList;
    
    
    numItems -=len;
    target.numItems +=len;
    
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
