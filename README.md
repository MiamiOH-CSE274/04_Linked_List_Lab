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

1. Yes all of them work based in that speed if i is zero or one smaller than the size.
2. They do.
3. remove and the destructor get rid of the correct things
4. yes it is just constant time but using numItems saves a jump

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
get would be faster but add and remove would be slower

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
make sure, make absolutely sure, you know what the hell your pointers are doing.
