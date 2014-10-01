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

1. works, accessing the first or last element always takes the same amount of time
2. works, the exception is thrown properly
3. works, destructor deletes every entry in the list
4. works, numItems is just returned

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

faster: get and set because they would just be array index lookups which is constant time

slower: add and remove because every other element in the list needs to be shifted after adding or removing in the middle of the list

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

i dont really have any questions about this exercise.  some advice would be to make sure you really understand what is going on with the way nodes store pointers to the ones around them and how those pointers are manipulated.
