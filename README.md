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

1. This requirement works. In add, remove, get, and set for each line the time per iteration is constant and the number of iterations are constant. Therefore the running time for each of these methods is constant or 0(1).
2. This requirement works. All methods that take index, 'i', throw a string exception if 'i < 0' or 'i > size()'. Only remove and get throw a string exception if i == size(). Add and find do not because in some cases i will need to equal size().
3. This requirement works. Memory is not being leaked. All Nodes are being deleted in the destructor.
4. This requirement works. Size() is 0(1) time. The time per iteration is constant and the number of iterations is constant so the running time will be constant.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

