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

1. yes
2. yes
3. yes
4. yes

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Adding or deleting in the middle of an ArrayList would be slower, but however a search would be faster. This is so because of a link list, you can go to the middle and add between two items and chaning those items links easily. Adding in the middle of array would have to loop through that index of the array which takes time. Searches in an array is faster because it doesn't have to look at each individual link like the linked list.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I think that the "add" method was explained in class very well, from that students can derive other methods after understanding the concept. I did the mistake of trying to code "Node* dummNote = new Node();" instead of "dummyNode = new Node();" though which was explained later by Dr. Brinkman, I suggests students look out for that and get help when needed.
