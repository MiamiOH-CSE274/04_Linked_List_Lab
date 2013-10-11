Author
==========
"Proctor, Patrick", proctopj
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

1. All of the methods mentioned run in constant time.
2. All methods required to throw error strings do so as needed.
3. I do not believe any memory is being leaked at this point.
4. Size is in constant time.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Arguably nothing would be faster except get due to array access time being constant. Having to iterate the elements of the list up or down each time we wanted to add/remove/getall 
would erase any performance gains in my opinion. In fact I'd argue they may even become slower given add and remove currently only require you to change 4 addresses whereas in an
array you'd have to move n-i items.
We'd also have to add a grow() function.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
As much of a headache as this lab is, you will be glad you know how to arrange LinkedLists. They are highly useful and work well in tandem with other data structures. 

