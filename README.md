Author
==========
Andy Shear, shearar
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

1. Add, remove, get, and set all take O(1) time when dealing with these values of i.  They are accessing either the head or the tail of the list, which is an O(1) operation because no parsing needs to occur.
2. Both find and remove contain this string exception.  They prevent the program from accessing any items out of bounds from the list.
3. The remove and destructor methods both delete the appropriate dynamically created data.
4. Size returns numItems, which contains the current number of items in the list.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

An ArrayList can access any variable at any index in O(1) time, in this case; find, get, and set would be faster.  However; add, remove, and splice would be slower, as items in the array must be re-indexed as they are added or removed.  A LinkedList can add or remove items in the middle of the list in O(1) time, while its find method takes O(n) to find the appropriate location.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

Draw out a linked list with example data before writing add() and remove().  It really helps to visualize how each of these operations are supposed to function when writing these methods.
