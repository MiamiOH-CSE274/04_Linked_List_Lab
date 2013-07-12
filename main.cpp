#include "LinkedList.h"
#include <iostream>

//Check to make sure that numItems returns correct result on a fresh
// instance of the LinkedList class
void testCtor(LinkedList<int>& testList){
  if(testList.size() == 0){
    std::cout << "SUCCESS: Fresh list has 0 items" << std::endl;
  } else {
    std::cout << "ERROR: Fresh list should have 0 items, but has " << testList.size() << std::endl;
  }
}

//Add and remove some items, making sure they come back in the
// correct order
void testAddRemove(LinkedList<int>& testList){
  testList.add(0,0);
  testList.add(0,1);
  testList.add(0,2);
  testList.add(3,3);
  testList.add(4,4);
  testList.add(5,5);

  if(testList.size() == 6){
    std::cout << "SUCCESS: 6 items added" << std::endl;
  } else {
    std::cout << "ERROR: Added 6 items, but size says " << testList.size() << std::endl;
    return;
  }

  int x0 = testList.get(0);
  int x1 = testList.get(1);
  int x2 = testList.get(2);
  int x3 = testList.get(3);
  int x4 = testList.get(4);
  int x5 = testList.get(5);

  if(x0 != 2 || x1 != 1 || x2 != 0 || x3 != 3 || x4 != 4 || x5 != 5){
    std::cout << "ERROR: Expected 2,1,0,3,4,5, but got " << x0 <<"," << x1 << "," << "x2" << "," << "x3" << "," << x4 << "," << x5 << std::endl;
  } else {
    std::cout << "SUCCESS: 6 added items came back out in the correct order" << std::endl;
  }

  testList.remove(5);
  testList.remove(0);

  if(testList.size() == 4){
    std::cout << "SUCCESS: 4 items after removing" << std::endl;
  } else {
    std::cout << "ERROR: Expected 4 items, but size says " << testList.size() << std::endl;
    return;
  }

  x0 = testList.get(0);
  x1 = testList.get(1);
  x2 = testList.get(2);
  x3 = testList.get(3);

  if(x0 != 1 || x1 != 0 || x2 != 3 || x3 != 4){
    std::cout << "ERROR: Expected 1,0,3,4, but got " << x0 <<"," << x1 << "," << "x2" << "," << "x3" << std::endl;
  } else {
    std::cout << "SUCCESS: After remove, 4 items came back out in the correct order" << std::endl;
  }

}

//A simple main function which creates a list, and tests it.
int main(){
  LinkedList<int> testList;
  testCtor(testList);
  testAddRemove(testList);

  return 0;
}
