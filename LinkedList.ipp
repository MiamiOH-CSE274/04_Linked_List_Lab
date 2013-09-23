//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  //TODO
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

    if( i < 0 || i >= numItems)
	  {

	  throw std :: string("Error! Invalid index!");

	  }

    //Creat a pointer points to the index i.
    Node * PointTo = find(i);
    
    //Set the value of index i to x.
    PointTo ->data = x;
    
    //Delete pointer.
    delete PointTo;
    
    PointTo = NULL;
    
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
   
    
    //Create a pointer points to the head of the node.
    Node * head;
    
    //Create a memory block in the Heap.
    //temp1 stores the address of the memory block.
    //For instance, let's say the address of temp1 is 150.
    Node * temp1 = new Node();
    
    //Set the item you want to add.
    temp1 ->data = x;
  
    //Increas the number of the item.
    numItems++;
    
    temp1 ->next = NULL;
    
    //Special case when n is 0.
    if(i == 0)
    {
       temp1 ->next = head;
       
       //head now stores the address 150 like temp1.
       head = temp1;
       return; 
    }
    
      if( i < 0 || i >= numItems)
       {
	      throw std :: string("Error! Invalid index!");
       }
    
    
    //temp2 now stores the address of head which is 150
    //Because I set temp2 as head.
    //Which means temp2 now points to head node.
    Node * temp2 = head;
    
    for(int i = 0;i<i-2;i++)
    {
        temp2 = temp2->next;
          
    }
    temp1 ->next = temp2->next;
    temp2 ->next = temp1;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
  //TODO
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  
    if( i < 0 || i >= numItems)
	   {
	  
	  throw std :: string("Error! Invalid index!");

	   }

   T ret;
  
   //Create a pointer points to item in the list that wants to be get.
   Node * pointer = find(i);
    
   ret = (pointer->data);
   
   delete pointer;
   
   pointer = nullptr;

   return ret;
}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  
  return numItems;
  
}
