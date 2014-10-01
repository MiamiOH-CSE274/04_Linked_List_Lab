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

1. Aside from the cost of find(i), add, remove, get, and set all operate in O(1).
2. The find(i) function throws the exception if i > size. For get(i) and set(i), if find(i) = dummy node they will throw an exception
3. I implemented remove() and the destructor the way I was taught in class and what I read in the text, so I do not believe it is leaking memory.
4. Size just returns numItems so it is in O(1) time.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
	If we implemented an arrayList instead of a LinkedList, get(i) would be shorter because it would run in constant time. However, adding and removing items requires
	the elements in the array to be shifted thus having a linear operational time. In a LinkedList, getNode(i) takes O(1+ min{i, n-i}) time, other than that all the other
	functions run in O(1) time.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
	Is there an immediate way to tell if my program is leaking memory if I miss something in my code.