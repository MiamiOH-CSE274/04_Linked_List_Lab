Author
==========
"Bickley, Daniel", bickledb
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

1. Add, remove, get, and set, should all take O(1) time, when i == 0 or i == (size() - 1). In each method, the reason why it does not allways take O(1) time is because it calls find(), which takes n time. However, find checks to see if i == 0 or i == size()-1, because those points are easy to get to using the dummyNode, and are always there, regardless of the size.
2. All of the methods with the index 'i' checks to see if i < 0 or i >= size, and returns strings if it cannot use that index.
3. Remove deletes the node after it is removed from the LinkedList, to prevent leakage. The destructor deletes the nodes one by one, until only the dummyNode is left, and it then deletes that dummyNode. 
4. Size() uses O(1) time, because it simply returns a variable that is changed with add() and remove().

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
In an ArrayList, the methods get, and set would all be faster. Get would be faster because ArrayLists utilize random access, so you would not have to loop through the entire List to find data in a specific index. Set would be faster for the same reason. The add and remove methods of the ArrayList would take up similar time to the LinkedList methods, provided add and remove only work on one side of the Arraylist. If you use an ArrayList when people want to add or remove a number that it is the middle, a LinkedList is always faster, because it does not need to move objects in the array to avoid empty space.
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
Pointers can be very confusing and very hard to work with. Do not jump straight in if you do not know what you are doing. After you learn a little bit of the pointer logic behind the code, everything will make more sense.
