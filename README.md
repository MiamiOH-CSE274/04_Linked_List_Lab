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

1. All of these methods take 0(1) time because they directly access the node that is being operated (or added) on. None of these methods depend on the size of the linked list because
	they are able to modify the list at any point through the memory locations of the nodes.
2. The exceptions have been coded in and all work. These exceptions check for out of bounds issues during handling of the index i variable.
3. Remove and the deconstructor both delete ALL unneeded elements. In deconstructor, this involves deleting all nodes as well as the dummy node, which is done with a for loop. In remove,
	this is done by creating a pointer to the removed element and then deleting it after node surgery has been completed.
4. Size is 0(1) time because it just returns a variable that is computed elsewhere in the class.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
	In a linked list, the add and remove methods are faster than that of the array list because they are able to directly access the nodes without having to perform operations on
	the rest of the list. In the array list, the get and set functions are faster than the ones in the linked list because the linked list needs to iterate through the nodes in order
	to get to the correct value. The array list can just access the array index using array operations.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
	One piece of advice is to really think about how to add a new node into the list. While I was coding, I thought that there would be many different scenarios for adding in a node, like
	putting it in front, in the middle, and in back. However, you will never be able to add an element to the back of the list because it will either move the already existing last element
	to the back of the line (becuase the ith position gets moved back), or an exception will be called. What I mean to say is not to overthing the functions of the linked list. The 
	logic is somewhat simple so go with your gut feeling.