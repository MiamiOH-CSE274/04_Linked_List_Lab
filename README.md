04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes

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

1. Working
2. working
3. Working
4. Working 

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

Set() and find()/get() would be faster because in ArrayLists we know exactly where something is, whereas in LinkedLists we need to first "find" where we are looking.
Add() and remove() would be slower because in ArrayLists you need to create another array and copy everything over if you are adding or removing something in the middle of the array.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I kept getting confused as the where the dummy node was, in the front as in position 0 or at the end as in position numItems.
