Author
==========
"Luo, Yu", luoy6
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

1. Add, remove, get, and set are O(1) if i==0 or if i==size()-1
2. All methods that take index, i, will throw a string exception if i<0 or i>=size
3. The remove and the destructor is doing the right thing.
4. Size() is O(1) time

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
If we did an ArrayList instead of a LinkedList, the get and set methods will be faster, and the add and remove methods will be slower. When using ArrayList, the relevant array item can be found in constant time, but when trying to add or remove item, many items has to be rearranged. 
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I was confused with the debugging process. I would suggest other students learn to how to do dubugging. 
