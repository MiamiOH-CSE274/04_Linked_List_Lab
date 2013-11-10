04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if `i == 0` or if `i == size()-1`
2. Add, remove, get, and set should throw a string exception if `i >= size()`. 
Find should throw a string exception if `i>size()`
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. `size()` is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

`add()` function works. I used double linked list.

`Remove()` function works. Switching pointers and deleted the node.

`get()` function works. Get the pointer points to index by using `find()` function, then return the value that stores in that memory address.

`Set()` function works. Get the pointer points to index by using `find()` function, then set the value to that memory address.

`Add()` function is `O(1)`. 

The test of throwing exception is successful.

Memory is not leaking. Called `remove()` function in destructure and deleted 
dummyNode.

`size()` is `O(1)` time. It simply just returns a value.


#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

The `remove()` method will definitely slower, because once you remove a item,
you will need move the rest of items forwardly or backwardly. The running time 
will be linear.

The `add()` method might even slower than `remove()` method. You are not only
need to move the rest of items forwardly or backwardly to make a room, but also you might need to resize the array if it is full. The `resize()`copy all of
elements from original array to new array.

The `add()` and `get()` method will be faster. ArrayList is random access table, `add()` and `get()` will be `O(1)`.


#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

Handling memory leak.



