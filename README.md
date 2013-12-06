Author
==========
"Bailey, Sam", baileys2
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

1. This requirement works because all four of those methods rely on find to locate the correct node, and find takes O(1) if either of those conditions is true.
2. This requirement works and was easy to complete, as all that was needed was a few simple "if, throw" statements at the beginning of each method.
3. This requirement works as it should, as both the destructor and remove delete unnecessary data when they are called.
4. This requirement works and was also very easy to complete, as the actual size method only needed to be one line long since all of the addition and subtraction of items was done in other methods.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

If we did an ArrayList instead of a LinkedList, the get and set methods would be faster, the add and remove methods would be slower, and the size method would remain the same.  The reason for all of these differences stems from the fact that
ArrayLists are much better at implementing random access of a file, while LinkedList goes through things as more of an ordered list (one at a time, from start to finish).  The get and set methods would be faster in an ArrayList because random access
allows users to very quickly go to a specific place in a file and take the appropriate action, while with the add and remove methods would be slower in an ArrayList because as the array gets bigger and bigger, more and more information from the old
version of the array would need to be copied into the new array with the added information (or without the deleted information).  Finally, size would not change speed between ArrayList and LinkedList as long as (in this program, at least) the numItems
variable was maintained throughout the different methods.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

One piece of advice I would share with students next semester is to not wait until the last minute to start working on a program.  This piece of advice has been given many many times, but it is still extremely true, and I know I have fallen victim to it many times.
By working ahead on assignments and getting started early, there is much more time to fix the mistakes that will be made (and trust me, mistakes are always made along the way), and there will be more time to get help by doing things such as going into office hours
you are stuck on a specific part of an assignment.