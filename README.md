Author
==========
"Emrick, Garrett", emrickgj
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

1. Add, remove, get, and set are all constant time (  0(1)  ). They all also work as expected.
2. All methods that take index check to make sure they don't go out of bounds, and throw exceptions when appropriate.
3. Memory in the program is not leaked, everything is cleaned up when it is no longer needed.
4. Size() is constant time. It is tracked throughout the program.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

        If we did an arraylist, accessing middle parts using a get() method would be faster as they are not required to loop through each of the pointers. The remove method would be slower in the middle
        due to the need to re-structure the array to account for the gap, while the link list could easily switch references. The link list is also much faster at concatenation, since it simply just needs
        to switch references around. Lastly, the add function will be faster in the long run, as they are added using references. With an arraylist, you would have to dynamically allocate a larger array to hold
        data, but this is not needed in a LinkedList.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
        
        Didn't really find anything confusing about this excercise, only reason I had issues was due to a dumb mistake on my part. 
