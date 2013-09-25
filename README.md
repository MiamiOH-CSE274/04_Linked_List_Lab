Author
==========
"Griffith, David", griffid5
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

1. All of this methods work. I know this because they passed all of Dr. Brinkman's test. Also based on the reading and how I coded everything should result in O(1).
2. Working. I know this because I passed all of Dr. Brinkman's tests and by looking over my code a few times, I am fairly sure I covered them all.
3. Working. Based on what we did in class there shouldn't be a memory leak.
4. Working. By simple returning numItems this is going to be constant time. 

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
For insertions and deletions (add and remove) linkedlist are much faster because they are constant time while in an arraylist they are linear. For get and set in an array it is constant time while it is linear in a linkedlist. 
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
The splice method is confusing since we shouldn't use add and remove but rather mess around with pointers. 
