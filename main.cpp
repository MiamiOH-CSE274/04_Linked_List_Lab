#include "LinkedList.h"
#include <iostream>

//Check to make sure that numItems returns correct result on a fresh
// instance of the LinkedList class
void testCtor(LinkedList<int>& testList){
  if(testList.getNumItems() == 0){
    std::cout << "SUCCESS: Fresh list has 0 items" << std::endl;
  } else {
    std::cout << "ERROR: Fresh list should have 0 items, but has " << testList.getNumItems() << std::endl;
  }
}

//Add and remove some items, making sure they come back in the
// correct order
void testAddRemove(LinkedList<int>& testList){
  testList.add(5);
  testList.add(10);
  testList.add(4);
  if(testList.getNumItems() == 3){
    std::cout << "SUCCESS: 3 items added" << std::endl;
  } else {
    std::cout << "ERROR: Added 3 items, but getNumItems says " << testList.getNumItems() << std::endl;
    return;
  }
  int x = testList.remove();
  int y = testList.remove();
  int z = testList.remove();
  if(x != 5 || y != 10 || z != 4){
    std::cout << "ERROR: Expected 5, 10, 4, but got " << x <<", " << y << ", " << "z" << std::endl;
  } else {
    std::cout << "SUCCESS: 3 added items came back out in the correct order" << std::endl;
  }
}

//Test to see if your list still works if we do add, remove, add, remove
// many times
void testAroundTheHorn(LinkedList<int>& testList){
  for(int i=0;i<1000;i++){
    testList.add(i);
    int t = testList.remove();
    if(t != i){
      std::cout << "ERROR: Added " << i << " but got back " << t << std::endl;
      return;
    }
  }
  std::cout << "SUCCESS: Added and removed 1000 items successfully" << std::endl;
}

//Test to see if your list can grow to handle lots of items
void testGrow(LinkedList<int>& testList){
  for(int i=0;i<1000;i++){
    testList.add(i);
  }

  if(testList.getNumItems() != 1000){
    std::cout << "ERROR: Should have 1000 items in list, but only found " << testList.getNumItems() << std::endl;
    return;
  }

  for(int i=0;i<1000;i++){
    int t = testList.remove();
    if(t != i){
      std::cout << "ERROR: Added " << i << " but got back " << t << std::endl;
      return;
    }
  }
  std::cout << "SUCCESS: Added 1000 items, then removed 1000" << std::endl;
}

//Test to make sure you are throwing an exception if remove is
// called improperly
void testRemoveException(LinkedList<int>& testList){
  try {
    int t = testList.remove();
  } catch (std::string s) {
    std::cout << "SUCCESS: Caught exception: " << s << std::endl;
    return;
  } catch (...) {
    std::cout << "ERROR: Caught an exception, but it wasn't a string type" << std::endl;
    return;
  }

  std::cout << "ERROR: Tried to remove from an empty list, but did not get an exception" << std::endl;
}

//A simple main function which creates a list, and tests it.
int main(){
  LinkedList<int> testList;
  testCtor(testList);
  testAddRemove(testList);

  return 0;
}
