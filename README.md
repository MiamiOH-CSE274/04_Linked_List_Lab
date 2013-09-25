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

1.add() function works. In order to figure out how to implement this function. 
I was thinking separate it into 3 cases. Adding items at the head of the list,
adding items at the middle of th list, and adding items at the tail of the list.Hence, adding items in the list arbitrarily is just about how to switch the pointer. Be careful the order of switching pointer when you are implementing this
method. And when you actually implement this function, you don't need to separate it into 3 cases, because IF statement will lower efficiency of program.

2. Remove() function works. This function is very similar with add() function, 
which is to switch the pointer. One extra thing you need to do is to delete the
pointer.

3. For splice() function, I didn't check how Dr.Bo tests it in main, because I am thinking to get in detailed in my next Shuffle project. I implemented it according to the comment in LinkedList.h. I heard there might be some issues of it, but so far, it works. By using a loop to take the items and add them to target
list, then remove them from original list.

4. get() function works. Get the pointer points to index by using find() function, then return the value that stores in that memory address.

5. Set() function works. Get the pointer points to index by using find() function, then set the value to that memory address.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

