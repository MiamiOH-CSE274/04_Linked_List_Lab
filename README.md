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

1. These functions should be running in O(1) if i == 0 || i == size()-1.  For both of these cases, the functions are doing simple operations that operate on only one item, no looping.
2. All methods that take the parameter i throw string exceptions if i is an invalid number, based on the size or elements in the DLL
3. Remove deletes pointers that have been passed to it, and the destructor uses remove() to delete all the nodes in the list, then calls delete to remove the dummyNode.  There should be no memory leaks.
4. Size is working in O(1) time by simply returning the member variable of our list, numItems.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

Find would be faster if we used an arrayList O(1), but adding and removing data would require a shift in the array, which consumes much more time than rearranging the pointers we use for the DLL.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

One piece of advice I would give to next semester's students is to use the tools that are given to you with the project.  The method testers are a great way to track your process for coding the problem, then you can use your own methods to test special cases afterward.
