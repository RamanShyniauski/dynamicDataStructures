//
//  deque.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 10/3/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    
    void push_back(T data);             //add element at the right end of a deque
    void push_front(T data);            //add element at the left end of the deque
    void pop_back();                    //remove element from the right end of a deque
    void pop_front();                   //remove element from the left end of the deque
    void clear();                       //clear deque
    void print();                       //print deque
    int getSize() { return Size; };     //get deque size
    T front();                          //get the first element
    T back();                           //get the last element
    
private:
    T *arr;
    T head;
    T tail;
    int Size;
};

template<typename T>
Deque<T>::Deque()
{
    Size = 0;
    arr = nullptr;
    head = tail = 0; //do not really need, but just for sure that head and tail are initialized
}

template<typename T>
Deque<T>::~Deque()
{
    delete [] arr;
}

template<typename T>
void Deque<T>::push_back(T data)
{
    if (Size)
    {
        T *tmpArray = new T[Size + 1];
        
        for (int i = 0; i < Size; i++)
        {
            tmpArray[i] = arr[i];
        }
        
        tmpArray[Size] = data;
        delete [] arr;
        arr = tmpArray;
        tail = arr[Size];
    }
    else
    {
        arr = new int[Size + 1];
        arr[0] = data;
        head = tail = arr[0];
    }
    
    Size++;
}

template<typename T>
void Deque<T>::push_front(T data)
{
    if (Size)
    {
        T *tmpArray = new T[Size + 1];
        
        for (int i = 0; i < Size; i++)
        {
            tmpArray[i+1] = arr[i];
        }
        
        tmpArray[0] = data;
        delete [] arr;
        arr = tmpArray;
        head = arr[0];
    }
    else
    {
        arr = new int[Size + 1];
        arr[0] = data;
        head = tail = arr[0];
    }
    
    Size++;
}

template<typename T>
void Deque<T>::pop_back()
{
    if (Size)
    {
        T *tmpArray = new T(Size - 1);
        
        for (int i = 0; i < Size - 1; i++)
        {
            tmpArray[i] = arr[i];
        }
        
        delete [] arr;
        arr = tmpArray;
        tail = arr[Size - 2];
        Size--;
    }
    else
    {
        throw std::out_of_range("can't remove element fron an empty dequeue");
    }
}

template<typename T>
void Deque<T>::pop_front()
{
    if (Size)
    {
        T *tmpArray = new T(Size - 1);
        
        for (int i = 0; i < Size - 1; i++)
        {
            tmpArray[i] = arr[i+1];
        }
        
        delete [] arr;
        arr = tmpArray;
        head = arr[0];
        Size--;
    }
    else
    {
        throw std::out_of_range("can't remove element fron an empty dequeue");
    }
}

template<typename T>
void Deque<T>::clear()
{
    if (!Size)
    {
        throw std::out_of_range("can't remove element fron an empty dequeue");
    }
    
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void Deque<T>::print()
{
    for (int i = 0; i < Size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template<typename T>
T Deque<T>::front()
{
    if (Size)
    {
        return head;
    }
    else
    {
        throw std::out_of_range("can't get element fron an empty dequeue");
    }
}

template<typename T>
T Deque<T>::back()
{
    if (Size)
    {
        return tail;
    }
    else
    {
        throw std::out_of_range("can't get element fron an empty dequeue");
    }
}
