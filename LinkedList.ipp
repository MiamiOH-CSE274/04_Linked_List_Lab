
//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
    T data;
    dummyNode= new Node();
    numItems=0;
    
    dummyNode->next=dummyNode;
    dummyNode->prev=dummyNode;
}

template <class T>
LinkedList<T>::~LinkedList() {
    while (numItems>0) {
        remove (0);
    }
    delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
    //Return a pointer to item i.
    //Special cases: If i == (numItems), return a pointer to the dummyNode
    //If i is an invalid number, throw a string exception
    
    int count= -1;
    Node* cur = dummyNode;
    
    if (i==numItems) {
        return cur;
    }
    if (i>numItems) {
        throw (std::string) "invalid number: not that many items in list";
    }
    while (count != i) {
        cur=cur->next;
        count++;
    }
    return cur;
    delete cur;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
    //Set the value at index i to x
    // If list does not contain i items, through a string exception
    
    if (i>numItems) {
        throw (std::string) "List doesn't have that many items";
    }
    if (i<0) {
        throw (std::string) "I must be positive.";
    }
    if (i==0) {
        dummyNode->next->data=x;
    }
    if (i == numItems) {
        dummyNode->prev->data=x;
    }
    else {
        Node* cur = find(i);
        cur->data = x;
    }
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
    //Add a new item, x, at position i. All items that were originally
    // at position i or higher get moved forward 1 to make room.
    // If list does not contain i items, through a string exception
    
    
    
    if (numItems<i){
        throw (std::string) "Error: Cannot add because there aren't that many items.";
    }
    if (i<0) {
        throw (std::string) "I must be positive.";
    }
    
    Node* temp = new Node();
    //to make add(0) take O(1)
    if (i==0) {
        Node* cur = dummyNode->next;
        temp->data = x;
        temp->next=cur;
        temp->prev = cur->prev;
        temp->prev->next = temp;
        temp->next->prev = temp;
        
        //temp->data=x;
        //dummyNode->next= temp;
        //dummyNode->prev=temp;
        //temp->prev=dummyNode;
        //temp->next=dummyNode;
    }
    //unable to get it for size()-1 to work in O(1) for add and remove.
    //code below is thought process that was unsuccessful
    else if (i==numItems-1) {
    Node* cur = dummyNode->prev;
    temp->data = x;
    temp->next=cur;
    temp->prev = cur->prev;
    temp->prev->next = temp;
    temp->next->prev = temp;
    
    }
    else {
        Node* cur = find(i);
        
        temp->data = x;
        temp->next=cur;
        temp->prev = cur->prev;
        temp->prev->next = temp;
        temp->next->prev = temp;
    }
    numItems++;
    
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
    //Remove the item at position i. All items that were originally
    // at position i+1 or higher get moved backwards 1 to fill the gap.
    // If list does not contain i items, through a string exception
    
    if (numItems==0) {
        throw (std::string) "array is empty";
    }
    if (numItems<i){
        throw (std::string) "Error: Cannot search because there aren't that many items.";
    }
    if (i==0) {
        Node* cur = dummyNode->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur; 
        
    }
    else if (i==numItems-1) {
    Node* cur = dummyNode->prev;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
        delete cur;
     }
    
    else{
        Node* cur = find(i);
        
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }
    numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
    if (i<0) {
        throw (std::string) "I must be positive.";
    }
    if (numItems<i){
        throw (std::string) "Error: Cannot search because there aren't that many items.";
    }
    if (i==0) {
        Node* cur= dummyNode->next;
        return cur->data;
        delete cur;
    }
    if (i==numItems-1) {
        Node* cur = dummyNode->prev;
        return cur->data;
        delete cur;
    }
    
    else{
        Node* cur = find(i);
        return cur->data;
        delete cur;
    }
    
    
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, LinkedList<T>& target, unsigned long t){
    //Remove len items, starting with index i, and insert into target list
    // at position t.
    // Node* temp = find(i);
    //Node* beforeSlicedSection = find(i-1);
    //Node* afterSlicedSection = find(i+len);
    //target.add(t, i);
    //beforeSlicedSection->next = afterSlicedSection;
    //afterSlicedSection->prev = beforeSlicedSection;
}

template <class T>
unsigned long LinkedList<T>::size(){
    
    return numItems;
}
