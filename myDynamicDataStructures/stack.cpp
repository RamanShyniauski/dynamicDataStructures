//
//  stack.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 9/30/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    
    void push(T data);                  //add element to the top of the stack
    T pop();                            //get the top element and remove it
    T peek();                           //get the top element without removing
    bool empty();                       //return boolean tru if stack is empty
    int getSize() { return Size; };     //get the size of the stack
    void print();                       //print all elements from top to bottom
    
private:
    template<typename TN>
    class Node
    {
    public:
        Node *pPrev;
        TN data;
        Node<TN>(TN data = TN(), Node *pPrev = nullptr)
        {
            this->data = data;
            this->pPrev = pPrev;
        }
    };
    
    int Size;
    Node<T> *top;
};

template<typename T>
Stack<T>::Stack()
{
    Size = 0;
    top = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
    while (Size)
    {
        Node<T> *tmp = top;
        top = tmp->pPrev;
        delete tmp;
        Size--;
    }
}

template<typename T>
void Stack<T>::push(T data)
{
    if (!Size)
    {
        top = new Node<T>(data);
    }
    else
    {
        top = new Node<T>(data, top);
    }
    Size++;
}

template<typename T>
T Stack<T>::pop()
{
    if (!Size)
    {
        throw std::out_of_range("can't remove element fron an empty stack");
    }
    else
    {
        Node<T> *current = top;
        T dataToReturn = current->data;
        top = top->pPrev;
        Size--;
        delete current;
        return dataToReturn;
    }
}

template<typename T>
T Stack<T>::peek()
{
    if (!Size)
    {
        throw std::out_of_range("can't read element fron an empty stack");
    }
    else
    {
        return top->data;
    }
}

template<typename T>
bool Stack<T>::empty()
{
    return !Size;
}

template<typename T>
void Stack<T>::print()
{
    Node<T> *current = top;
    for (int i = 0; i < Size; i++)
    {
        std::cout << current->data << std::endl;
        current = current->pPrev;
    }
}
