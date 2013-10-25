Author
==========
"Monnin, Sebastian", monninse
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

1. add, remove,get and set all are o(1), they all work as they should
2. all methods throw string exections when i isn't correct
3. no memory leaks, remove and the destructor both work corretly with no memory leaks
4. size is constant time and works correctly

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
 If we did an arraylist the get set methods would be faster because of the indexes in an array, therefore it would be constant time where as the add and remove methodes would be slower because rearranging an array takes a lot longer than a linked list
       

       
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I had a hard time understand exactly what splice was supposed to do at the start. So maybe just a bit more info on that. Over all I thought it was pretty straight forward

         
