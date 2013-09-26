Author
==========
"Decker, Benjamin", deckerbd
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

1. Completed.
2. Should be doing so, but runtime errors preventing me from telling for sure.
3. Completed.
4. Completed.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Removing from the ArrayList in the middle or towards the early sections of the array would take substantially longer, due to the fact that you'd have to shift all the values after it down a space, which takes quite a bit of time. Finding a certain node in the list is faster in the ArrayList over the LinkedList due to being able to access the node immediately, unlike the linked list where you must transverse through the array to get to the node you want.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
If you get runtime errors, try to use the debugger the best that you can. Also, watch for casting errors, and pointers will make you cry.
