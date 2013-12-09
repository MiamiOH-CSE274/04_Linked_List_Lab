Author
==========
"Decker, Benjamin", deckerbd
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

1. Works in required way in required time.
2. ^
3. ^
4. ^

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.

Removing from the ArrayList in the middle or towards the early sections of the array would take substantially longer, due to the fact that you'd have to shift all the values after it down a space, which takes quite a bit of time. Finding a certain node in the list is faster in the ArrayList over the LinkedList due to being able to access the node immediately, unlike the linked list where you must transverse through the array to get to the node you want.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

If you get runtime errors, try to use the debugger the best that you can. Also, watch for casting errors, and pointers will make you cry.


Running Time Analysis
===========

#### 1. add - For add, every line except for the one referring to find will perform in constant time due to not being affected by the list's size. However, because we call find which could have a runtime of either linear or constant, it's possible to have add technically perform in linear (O(n)) time over constant (O(1)) time. Since we know (or will know if you read about find below) that find will perform at constant time if passed 0 or size()-1, and size is constant, we know the runtime under those two conditions will be constant time. If our value isn't to be added onto the beginning or end however, add will perform in linear time due to find performing in linear time.

#### 2. find - find actually has two different performance times: linear time (O(n)) and constant time (O(1)). For the special cases where we're trying to find a value equal to the head or end, we know we can return the dummyNode and dummyNode->prev, respectively. However, for any index that doesn't happen to be these, we'll have to loop through the list until we find it. This will take linear time (O(n)) due to this being affected by both the size of the array, and the index to look up.

#### 3. set - If we're passed a value which is greater than or equal to numItems or less than zero, the running time will be based upon the speed of throw, which I'm assuming is constant time. Since set also uses the find method like add does, when the passed index to set is equal to 0 or size()-1, this will perform in constant time for the same reasons outlined above. Also, for the same reasons outlined above, the line with find will perform in linear time (O(n)) when passed a value other than those two special values, making set also perform in linear time.

#### 4. remove - In the case that our array is empty, this will run in constant time (O(1)) assuming that throwing the string exception is constant time. However, if our array isn't empty, this method may also be in either linear time (O(n)) or constant time (O(1)). This depends yet again on the fact that we're calling the find method. For yet again the same reasons outlined above, as long as the index to check is equal to 0 or size()-1, this method will perform in constant time, otherwise it'll perform in linear time.

#### 5. size - since this is just returning a local int and the size of the list doesn't affect this line's running time at all since nothing is being added or removed from the list in this method, the running time for this method is constant time (O(1)).

#### 6. constructor - Because the constructor is just 4 instructions, none of which are dependent on the number of items in the LinkedList, the constructor will perform in constant time (O(1)).


#### 7. destructor - Due to having to remove every node in the LinkedList, the time this function will take to finish will increase depending on the amount of nodes within the LinkedList, giving us a running-time of linear (O(n)) time.