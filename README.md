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

1. All work in constant time. (to fix the size()-1 condition all I needed was "else if", not just an if statement.)
2. all throw exception under these conditions
3. memory is not leaked (destructor deletes all nodes
4. size() is O(1)

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
faster: find, as in linked list we have to keep running through each node to get to the desired index. add and remove are faster in linked list as we just change the pointers to eliminate or add a new node without having to move every node.
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester? I was troubled with slice before the update, but for the most part i believe it is a straightforward lab. I especially recommend drawing out the nodes when trying to figure out how to add, and remove.

