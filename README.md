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

1. Yes, all will throw an exception if that is the case. ((exception is first thing in the class))
2. Yes, same exceptions as above.
3. The destructor deletes all nodes.
4. Yes, numItems is a variable. Returning it is constant time.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
	Add and remove would be O(n) time instead of constant, so they would be slower. Instead of adding where ever we want with LinkedLists, we'd
have to shift everything down in an array, making it linear time. Getting random access variables would be faster. So we'd be able to find and change data
in an arraylist quicker than a linkedlist.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
	**you answered it in class ->The role of the destructor. Do you only delete variables made in the contructor? Or do you delete everything you made through the program?
