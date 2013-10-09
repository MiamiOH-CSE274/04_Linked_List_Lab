04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if `i == 0` or if `i == size()-1`
2. All methods that take index, `i`, should throw a string exception if `i < 0` or `i >= size()`
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. `size()` is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Running Time Analysis
=====================
1. find() method has a running time of O(n). Each line of code, except the for loop section, in the find() method takes constant time (assuming function call of throw() takes constant time).  The for loop will loop n (n is the value of i) times to find a particular node. Thus, the find() method has a running time of O(n), where n is the value of i. If  if 'i==0', the loop will only loop one time. If 'i==size()-1', the find function will not enter the loop. Thus, if  if 'i==0' or if 'i==size()-1', the find() method will have a running time of O(1). 
2. if 'i==0' or if 'i==size()-1', then add() method has a running time of O(1); otherwise, the add() method will have a running time of O(n), where n is the number of nodes in the linked list from 0 to i. Each line of code, except the function call to find(), in the add() method takes constant time. If 'i==0' or if 'i==size()-1', the find() method only takes constant time, otherwise, the find() method will take O(n) time. 
3. if 'i==0' or if 'i==size()-1', then get() method has running time of O(1); otherwise, the get() method will have a running time of O(n). The get() method calls find() method, thus, the running time of get() will depend on the running time of of find(). 
4. if 'i==0' or if 'i==size()-1', then the set() method has a running time of O(1); otherwise, the set() method will have a running time of O(n). The set() method calls find() method, thus, the running time of set() will depend on the running time of find(). 
5. if 'i==0' or if 'i==size()-1', then remove() method has a running time of O(1); otherwise, the add() method will ahve a running time of O(n), where n is the number of nodes in the linked list from 0 to i. Each line of code, except the funciton call to find(), in the remove() method takes constant time(assuming function call of throw() takes constant time). If 'i==0' or if 'i==size()-1', the find() method only takes constant time, otherwise, the find() method will take O(n) time.
6. the size() method has one lie of code that returns a interger of numItems. This line of code has a constant running time, and thus, the size() method has a running time of O(1).
7. the running time of the splice() method is depending on the running time of the find() method. I called find() method three times in the splice() method. Worst case senario, the find() method will have a linear running time, and thus the splice() will also have a running time of O(n). 

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add, remove, get, and set are O(1) if i==0 or if i==size()-1
2. All methods that take index, i, will throw a string exception if i<0 or i>=size
3. The remove and the destructor is doing the right thing.
4. Size() is O(1) time

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
If we did an ArrayList instead of a LinkedList, the get and set methods will be faster, and the add and remove methods will be slower. When using ArrayList, the relevant array item can be found in constant time, but when trying to add or remove item, many items has to be rearranged. 
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I was confused with the debugging process. I would suggest other students learn to how to do dubugging. 
