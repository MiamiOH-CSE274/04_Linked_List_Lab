Author
==========
"Contini, Nick", continnd
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

1. Works, since no matter how many elements are in the list, the program will always create/remove one new node, and then change 2 prev pointers and 2 next pointers for add/remove. Get and set also simply have to retrieve/change the data variable in the node, which will be the same for any amount of elements. Since the find method only takes one operation to get the pointer for the desired index of the first or last element, it helps keep these operations constant.
2. Works, since it is simply controlled with an if statement to check to see if the index exists in the list.
3. Works, in the destructor, I continue to delete the node next to the dummyNode, until dummyNode->next=dummyNode, and then I delete the dummyNode. In remove, I make sure to use delete on the node to be removed after reassigning pointers.
4. Works, simply keeps track of numItems while adding and removing and return the value.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
Add and remove would be slower, since it would have to shift values over to either make room for an added value, or to fill in an empty space created by a removed element. Get and set would be faster, since the ArrayList does not need to search for the index, it has it's own easy to find variable.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
Remember that a node contains three elements. It contains the adress of the node before it, the node after it, and then meaningful data. You have to move from node to node, and the nodes will eventually point back to the dummyNode, which is the link between the end and the beginning of the list. Keep in mind you can move both directions. For example, if you are at the positive x-axis, and you want to get to the negative y-axis by taking a path of a circle, it's faster to travel backward (clockwise) than traveling forword (counterclockwise).
