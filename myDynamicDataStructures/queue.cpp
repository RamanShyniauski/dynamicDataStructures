//
//  queue.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 10/2/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    
    void push(T data);      //add element to the queue
    void pop();             //remove the first element from the queue
    T front();              //get the first element
    T back();               //get the last element
    bool empty();           //check is queue empty
    
private:
    template<typename TN>
    class Node
    {
    public:
        TN data;
        Node *pPrev;
        
        Node<TN>(TN data = TN(), Node *pPrev = nullptr)
        {
            this->data = data;
            this->pPrev = pPrev;
        }
    };
    
    int Size;
    Node<T> *head;
    Node<T> *tail;
};

template<typename T>
Queue<T>::Queue()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
    while (Size)
    {
        Node<T> *tmp = head;
        head = tmp->pPrev;
        delete tmp;
        Size--;
    }
}

template<typename T>
void Queue<T>::push(T data)
{
    if (Size)
    {
        Node<T> *current = this->head;
        
        while (current->pPrev != nullptr)
        {
            current = current->pPrev;
        }
        
        current->pPrev = tail = new Node<T>(data);
    }
    else
    {
        head = tail = new Node<T>(data);
    }
    
    Size++;
}

template<typename T>
void Queue<T>::pop()
{
    if (Size)
    {
        Node<T> *temp = this->head;
        head = head->pPrev;
        Size--;
        delete temp;
    }
    else
    {
        throw std::out_of_range("can't remove element from an empty queue");
    }
}

template<typename T>
T Queue<T>::front()
{
    if (Size)
    {
        return head->data;
    }
    else
    {
        throw std::out_of_range("can't get element from an empty queue");
    }
}

template<typename T>
T Queue<T>::back()
{
    if (Size)
    {
        return tail->data;
    }
    else
    {
        throw std::out_of_range("can't get element from an empty queue");
    }
}

template<typename T>
bool Queue<T>::empty()
{
    return !Size;
}
