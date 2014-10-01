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

1. TODO
2. TODO
3. TODO
4. TODO

2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
	
	a. If we did a LinkedList, get() and set() would be slower because it will have to loop through the list to find 	the thing that you are looking for. ArrayList is O(1) for these, while LinkedList is O(n).
	b. Add() and remove() would be faster because ArrayList is O(n) for those functions, and LinkedList is O(1).

3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

	I would suggest that students review the way you find the location of a variable versus the actual thing in the variable, and vice versa. I messed this up once or twice in my program, and couldn't figure out why it wouldn't work until I realized my mistake. Being new to C++ is a little confusing, and learning how to "think in C++" will help a lot.
