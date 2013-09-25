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

1. This works.  If i is the first or last index, then find will get the correct Node the first time it goes through its loops.
2. Yes, all of the functions that have a parameter i throw string exceptions if the index value is invalid.
3. Yep, my remove and destructor methods should be doing the correct thing.
4. I update numItems anytime add or remove alter the list, so size() is constant time.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

Find would be quicker because with an Array you can just access the index you want.  With our List, you have to go in sequential order.  Add and remove would be slower with an ArrayList, because when you add something you have to push everything that comes after it over one spot and when you remove something you have to move things back to fill the whole.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

