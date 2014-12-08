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

1. add remove get and set all act on the same timeframe reguardless of number of items in the linked list.
2. all methods should return a string error if they ask for an item that isnt in the list.
3. all things are deleted as they become irrelevant and dummy node is the last item to be deleted.
4. size returns only the variable numItems which is changed as the other methods run.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
get and set would be faster on arraylist while add and remove would be slower.
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
My biggest question is what causes my program to crash? From this perhaps better error handling would lead to a solution.