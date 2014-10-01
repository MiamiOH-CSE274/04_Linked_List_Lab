04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if `i == 0` or if `i == size()-1`
2. Add, remove, get, and set should throw a string exception if `i >= size()`. Find should throw a string exception if `i > size()`
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. `size()` is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. TODO
2. SUCCESS, when I tested my code for poor index values using your testers, they returned proper error messages from my throw statements.
3. SUCCESS, I delete nodes and dummyNodes in the right order so that I make sure there are no dangling pointers that just take up memory.
4. SUCCESS, add() increments numItems by one if an exception is not thrown, remove() decrements numItems by one if an exception is not thrown, which keeps track of numItems perfectly, allowing me to just return numItems when size() is called.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
	- Since we used Linked List, the two methods that are a lot faster are add() and remove().  In ArrayList, if we were to add or a remove a method in the middle of the list, we would delete the data and shift every other piece of data one position over so as to make sure there is no gap.  Since this process takes longer for more items because we shift more items individually, the time it takes for add() and remove() is O(n), or linear time.  Add() and remove() for LinkedLists require a constant number of steps: changing the pointers of the nodes before and after the addition or subtraction to point where they should, giving us a constant time function, or O(1).  Get() in LinkedList is longer though because we call the find() function, which runs in O(n) time, meaning get() for LinkedList is also linear time.  get() for ArrayList is constant time though because we are only returning a value, and no other searching/finding needs to be done.  Besides that, LinkedList and ArrayList run at the same, constant speeds.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
	- How does using find() and passing the Node as a parameter speed up a method? I get if you look at JUST that method, it runs in constant time, but instead of method->find->actions, you do find->method->action, which seems to be the same time/efficiency. 
