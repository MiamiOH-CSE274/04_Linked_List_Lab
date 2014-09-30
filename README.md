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

1. Add, remove, get, and set all use find(), which is the slowest part of each method. The find() method we wrote in class would run in constant time when 'i==0'; since we started at the beginning of the list, the first check would be when i==0 and we would not have to cycle through a lot of indexes. However, I had to revise the method to make it run in constant time when i==size()-1. After reading the book, I learned that a good way to write the find() method would be to check whether i falls in the first or last half of the list, and then start looking at either the front or the end of the list. If i is near the back of the list, cycle backwards through the list starting with i = size() - 1. This would also cause find() to run in constant time for i==size()-1. Therefore, since find() runs in constant time for both i==0 and i==size()-1, add, remove, get, and set would be the same since their run times depend on find(). 
2. Find does throw a string exception when i > size(). Add, remove, get, and set all use find(), so they will throw find's string exception if i > size().  Get, set, and remove all have their own string exceptions if i equals the size of the list. Though I know the instructions say that add should throw an exception if i = size(), I felt this was incorrect. If you wanted to add an item to the end of the list, you would want the index of that item to be the value of numItems.  This should not affect the actual dummyNode, because add just manipulates where the next and prev pointers are pointing.
3. I believe this is working correctly. In remove, the node that is being removed is deleted. Since "removedNode" is a local variable, it goes out of scope when the method ends, and thus is not a dangling pointer. In the destructor, remove is used to delete all the nodes with data in the list. The dummyNode is then deleted, and "dummyNode" is set to NULL, so it is no longer a dangling pointer.
4. size() takes constant time because all it does is return the value of the variable numItems.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
When using an ArrayList as opposed to a LinkedList, there are different changes in runtime based on the inherent structures. An array-based list can offer easy access to any value in the array, so get(i) and set(i,x) can run in constant time. However, arrays are not very dynamic, so adding and removing from the middle of the array requires shifting the elements to fill in the gap, which takes linear time.  On the other hand, linked lists are more dynamic, so add(i,x) and remove(i) can take constant time (though in this assignment they take O(n) time due to having to cycle through all the nodes to find the right one). It is harder to access a specific value in the list, however, so get(i) and set(i,x) take linear time. Therefore, if we used ArrayList instead of a LinkedList, get(i) and set(i,x) would be faster, but add(i,x) and remove(i) would be slower. 
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
Advice to future students: read your code carefully! When I went back through after I thought I was finished, I found so many places where I could increase efficiency and make my code more readable. 