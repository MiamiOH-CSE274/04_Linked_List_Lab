04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if `i == 0` or if `i == size()-1`
2. All methods that take index, `i`, should throw a string exception if `i < 0` or `i >= size()`
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. `size()` is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Working, based on tests, logic, and examples from book.
2. Working, find() method properly throws a string exception based on all cases that require it.
3. Working, destructor both removes each node iteratively and removes the dummyNode afterwards.
4. Working, constant time because numItems stores the number of items in the list, all I am doing is returning that value.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Both the get() method and set() method would be faster in an ArrayList since they are constant time, whereas in the LinkedList we have to use the find() method which is not in constant time.  Yet for an ArrayList the add() and remove() methods would both be slower since ArrayList requires shifting every element iteratively.  
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
This homework as with all is better to get started early, it's really easy to make simple errors that can turn into hours of frustration.  Solving even these simple issues is not something to be done last minute.
