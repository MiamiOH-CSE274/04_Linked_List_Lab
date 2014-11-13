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

1. Works! add(), remove() and get() work in O(1) only when the index given is equal to 0 or numItems, otherwise the program must loop through the nodes to find the correct one.
2. Works! add(), remove(), and find() all throw a string exception if the index is out of bounds.
3. Works! Remove deletes the pointer variables that it created and the destructor makes sure to delete the dummy node.
4. Works! size() only has to return the variable that stores the number of items in the list which take constant time.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
				LinkedList Runtimes: size() = O(1), add() = O(1), remove() = O(1), set() = O(n), get() = O(n)
				ArrayList Runtimes: size() = O(1), add() = O(n), remove() = O(n), set() = O(1), get() = O(1)
				
				So if we used an ArrayList instead of a LinkedList our add() and remove() methods would be faster, our set() and get() methods would be slower, and size() would be the same.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
				In the comments that you left for the add() and remove() methods it says that the other nodes will have to be pushed away from or pulled toward the index where we added/removed in order to accommodate the added/removed node. Isn't this what using a linked list is trying to prevent? That is, we don't want to have to move the other items in the list because that would require O(n) time instead of O(1) time.