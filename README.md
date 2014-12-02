04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if 'i == 0' or if 'i == size()-1'
2. Add, remove, get, and set should throw a string exception if 'i >= size()'. Find should throw a string exception if 'i > size()'
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. 'size()' is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. These are all O(1) if i is at the end or beginning of the list, as all actions from these methods will occur directly around the current location of i.
2. Yes, I added this for all methods which deal with an index that could possibly be outside the bounds of the list. If that happens, a string exception is thrown which tells the user what method is throwing the error.
3. The remove method and the destructor both delete any unused memory to prevent leakage.
4. Of course, size() is essentially a getter, it is always O(1).

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Same: size()
Faster: remove(),  set(), get()
Slower: add()
The size method is just a getter, it never really varies in speed.
Remove is faster with ArrayList because there is no need to find the node, pair up nodes linked to it, then delete it. Instead, ArrayLists can just remove the element from the list. Set is also faster with ArrayList because an ArrayList would only need to call the index and replace the data rather than find a node. Get requires calling the find method in a LinkedList, so it is quite slow compared to that of an ArrayList.
Add is faster with LinkedList because we simply link the surrounding nodes to the new node, rather than iterate through an ArrayList and bump all elements up.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Draw out linked list operations and others like it. It really helps to visualize it before coding.
