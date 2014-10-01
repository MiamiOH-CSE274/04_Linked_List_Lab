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

1. All 4 are constant time because they do not depend on the size of the list.
2. All methods throw string exceptions.
3. Memory should not be leaking, all objects are deleted when methods finish.
4. Size is O(1) time since only a variable is returned.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Get and set would be faster in an ArrayList because ArrayLists can access data members without going through the entire list.
Add and remove should be faster in a LinkedList, as size does not matter, only pointers change to point around the old node.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I think it should be explained in the very beggining how changing pointers is the main idea behind adding and removing nodes. 