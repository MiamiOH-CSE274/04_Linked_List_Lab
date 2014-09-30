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

1. works, all work in constant time because there are no loops to complete the action
2. works, all properly throw a string exception if the index given doesn’t meet the required cases
3. works, remove properly deletes the node being removed and the destructor using remove to get rid of every node in the list along with the dummy node.
4. works, size() simply just returns numItems which is in constant time. 

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

In a LinkedList add and remove would be faster because you can directly access the nodes without having to do anything to the rest of the list. In an ArrayList get and set would be faster because in an array list a value can be reached by using array operations, while in a LinkedList you have to iterate through the nodes in order to get the value wanted. 

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

Some advice that I would give would be to draw out the add and remove functions on a white board or a piece of paper. Seeing the nodes really helps you to understand how the functions work. If you don’t visually see what you are doing in these methods they can really throw you for a loop. As Dr. Brinkman said it truly is mental gymnastics.
