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

add() function works. In order to figure out how to implement this function. 
I was thinking separate it into 3 cases. Adding items at the head of the list,
adding items at the middle of th list, and adding items at the tail of the list.Hence, adding items in the list arbitrarily is just about how to switch the pointer. Be careful the order of switching pointer when you are implementing this
method. And when you actually implement this function, you don't need to separate it into 3 cases, because IF statement will lower efficiency of program.

Remove() function works. This function is very similar with add() function, 
which is to switch the pointer. One extra thing you need to do is to delete the
pointer.

For splice() function, I didn't check how Dr.Bo tests it in main, because I am thinking to get in detailed in my next Shuffle project. I implemented it according to the comment in LinkedList.h. I heard there might be some issues of it, but so far, it works. By using a loop to take the items and add them to target
list, then remove them from original list.

get() function works. Get the pointer points to index by using find() function, then return the value that stores in that memory address.

Set() function works. Get the pointer points to index by using find() function, then set the value to that memory address.


Add() function is O(1). Every line of code is either creating a new memory 
block or switching the pointers.

The test of throwing exception is successful.

Memory is not leaking, delete dummyNode. By using remove() function to keep
deleting node at the beginning of the list.(loop)

size() is O(1) time. It simply just returns a value.


#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

The remove() method will definitely slower, because once you remove a item, you 
will need move the rest of items forwardly or backwardly. The running time will depend on how many items in the array.

The add() method might even slower than remove() method. You are not only need to move the rest of items forwardly or backwardly to make a room,which the running time will depend on the number of items in the array, but also you might need to resize the array if it is full. The resize() method will have a loop to copy
your original array to a new array, the running time will also depend on
the number of items in the array.

The add() and get() method will be faster. Because in ArrayList you can just
return the value or set the value to that index. But in linkedList, you will 
need to get the memory address of that index by using find() method. The find()
method will have a loop to find the address of that index, the running time
will depend on the amount of items in the list and the size of index you are
inserting to it.


#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

To understand the implementation of linkedList, we need to understand what goes
where, what section of the memory, what is the scope of variables, what goes to
stack section of memory and what goes to heap section of memory. 



