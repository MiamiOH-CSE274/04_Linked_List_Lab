//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List <T> {
 public:
  //See List.h for documentation of these methods

  unsigned long getNumItems();

  //Initialize all private member variables.
  // Be sure to create the dummy node using "new"
  LinkedList();
  //Delete any dynamically allocated memory. You will need to loop
  // through all your nodes, deleting them one at a time
  virtual ~LinkedList();

 private:
  //Pointer to the dummy node.
  Node* dummyNode;
  
  //Number of items in the list
  unsigned long numItems;
};

#include "LinkedList.ipp"
