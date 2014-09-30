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

1. Affirmative, all functions possible to run in constant time run in constant time. (As far as I know...hehe)
2. Actually, no.  This may not work, I can't tell.  For some reason if I change my i > numItems check to i >= numItems, the program quits working after the first test. Everything else works splendidly.
3. No leaks here, or so I hope.  99% sure....
4. size() is so simple, I'm pretty sure it's working correctly but I honestly don't know how to check in this case.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

For all intents and purposes, the LinkedList and ArrayList are opposites in terms of time.  The methods that are linear in an ArrayList are constant in a LinkedList and vice-versa.  That said, neither one would be "faster", each one has it's own specialty.

However, if we did an ArrayList...our get() and set() methods would speed up (but our other methods would all slow down).  It's a matter of which methods you use more often, from my point of view.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

Last week my advice was just to read the book, but this week I read the book before we even got started talking about this homework and I felt super on top of things all week. So don't just read the book, but the sooner you read it the better!

