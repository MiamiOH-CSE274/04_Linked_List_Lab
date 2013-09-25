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

1. Add, remove, get, and set are O(1) if i is referring to the first or last node because I use an if statement to check if i is the index of the last node.
2. Exceptions are thrown when i is >=size() in the find method, which is called by any method that takes index `i`.
3. The destructor calls remove() to delete individual nodes, and then when there are no nodes left, the destructor deletes the dummy node.
4. size() is O(1) because numItems is incremented appropriately when a node is added or deleted, and the size() method just returns the value of numItems.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

If an ArrayList was used instead of a LinkedList, the `get()`, `set()`, `remove()`, and `add()` functions will be faster because you do not have to travel through a set of pointers to reach the destination; you can access the data in the ArrayList quicker. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I think this exercise wasn't confusing, but I would tell students to look up how the `->` syntax is used, as that was the key to understanding how to write this program, for me at least.

