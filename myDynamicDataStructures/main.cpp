//
//  main.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 9/25/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <iostream>
#include "singleLinkedList.cpp"
#include "doublyLinkedList.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "deque.cpp"
#include "binaryTree.cpp"
#include "map.cpp"

using namespace std;

int main()
{
    /*
                                                Hi there!
    You can check my realisaion of the following dynamic data structures:
    - Single Linked List
    - Doubly Linked List
    - Stack (based on single linked list)
    - Queue (based on single linked list)
    - Deque (based on dynamic array)
    - Binary Tree
    - Map (Binary Tree based)
     
    All methods have description in the .cpp files. Here you can find some examples of how they work.
     
                                                 Enjoy!
    */
    
    /*
    // Just a small example to show how Doubly Linked List works
    
    DoublyList<int> listDouble;
    
    int numbersCountDoubly;
    cout << "How many elements will be in your doubly linked list?" << endl;
    cin >> numbersCountDoubly;
    
    if (numbersCountDoubly <= 0)
    {
        cout << "Cmon, try again and give me a positive number" << endl;
        return 0;
    }
    
    for (int i = 0; i < numbersCountDoubly; i++)
    {
        listDouble.push_back(rand() % 10);
    }
    
    cout << "Here is your double linked list: " << endl;
    listDouble.print();
     
    cout << "Seems that we've done. Cool! You can also check the following methods for a doubly linked list: \n .push_back(T data) - push data at the end of a list \n .push_front(T data) - push data at the beginning of the list \n .pop_back() - remove tail \n .pop_front() - remove head \n .insert(T value, int index) - insert value at index \n .removeAt(int index) - remove value at index \n .clear() - remove all values from a list \n .print() - print out a list \n .getSize() - return size of a list \n doublyList[int index] - return element at index position \n\n\tHAVE FUN!!!\n" << endl;
     */
 
    
    Map<int, string> q;
    
    q.insert(1, "a");
    q.insert(2, "b");
    q.insert(3, "b2");
    
    string z = q.searchByKey(2).value;
    cout << z;
    
}
