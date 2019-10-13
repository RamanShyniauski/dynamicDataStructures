//
//  doublyLinkedList.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 9/29/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class DoublyList
{
public:
    DoublyList();
    ~DoublyList();
    
    void push_back(T data);             //add element at the end of the list
    void push_front(T data);            //add element at the beginning of the list
    void pop_back();                    //remove element from the end of the list
    void pop_front();                   //remove element at the beginning of the list
    void insert(T value, int index);    //insert value at index
    void removeAt(int index);           //remove value at index
    void clear();                       //clear list
    void print();                       //print list
    int getSize() { return Size; };     //get list's size
    T& operator[](const int index);     //get element at index
    
private:
    template<typename TN>
    class Node
    {
    public:
        Node *pNext;
        Node *pPrev;
        TN data;
        Node(TN data = TN(), Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev; //pointer to a previous element
        }
    };
    
    int Size;
    Node<T> *head;
    Node<T> *tail;
};

template<typename T>
DoublyList<T>::DoublyList()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoublyList<T>::~DoublyList()
{
    clear();
}

template<typename T>
void DoublyList<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = tail = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = tail = new Node<T>(data, nullptr, current); //add pPrev = *current for a newly created element
    }
    
    Size++;
}

template<typename T>
void DoublyList<T>::push_front(T data)
{
    if (Size)   //check is list blank or not
    {
        Node<T> *current = head;
        head = new Node<T>(data, head);
        current->pPrev = head;  //point to a new head
    }
    else { head = tail = new Node<T>(data); }   //if blank head == tail and both of them has pPrev = pNext = nullptr
    
    Size++;
}

template<typename T>
void DoublyList<T>::print()
{
    Node<T> *current = this->head;
    
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
}

template<typename T>
void DoublyList<T>::insert(T value, int index)
{
    if ((index != 0 && index > Size - 1) || index < 0)
    {
        throw std::out_of_range("position is out of range");
    }
    
    if (index == 0)
    {
        push_front(value);
        return;
    }
    
    if (index <= Size / 2)  //check is it better start from tail or from head
    {
        Node<T> *previous = this->head;
        
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        
        Node<T> *next = previous->pNext->pNext; //and pNext fro him again
        previous->pNext = next->pPrev = new Node<T>(value, previous->pNext, previous);
    }
    else    //start from tail
    {
        Node<T> *next = this->tail;
        
        for (int i = 0; i < Size - index - 1; i++)
        {
            next = next->pPrev;
        }
        
        Node<T> *previous = next->pPrev;
        next->pPrev = previous->pNext = new Node<T>(value, next, previous->pNext);
    }
    
    Size++;
}

template<typename T>
void DoublyList<T>::pop_back()
{
    if (head->pNext) //check is our head a tail; if that's true we will not be able to set new head to a nullptr
    {
        Node<T> *current = this->tail;
        this->tail = current->pPrev;
        this->tail->pNext = nullptr;
        delete current;
    }
    else //delete value and clear all pointers
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    Size--;
}

template<typename T>
void DoublyList<T>::pop_front()
{
    if (head->pNext) //check is our head a tail; if that's true we will not be able to set new head to a nullptr
    {
        Node<T> *temp = this->head;
        this->head = head->pNext;
        head->pPrev = nullptr;
        delete temp;
    }
    else //delete value and clear all pointers
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    Size--;
}

template<typename T>
void DoublyList<T>::removeAt(int index)
{
    if (index > Size - 1 || index < 0)
    {
        throw std::out_of_range("position is out of range");
    }
    if (index == 0)
    {
        pop_front();
        return;
    }
    else if (index == Size - 1)
    {
        pop_back();
        return;
    }
    
    if (index <= Size / 2) //start from head
    {
        Node<T> *previous = this->head;
        
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        
        Node<T> *next = previous->pNext->pNext;
        previous->pNext = next;
        next->pPrev = previous;
    }
    else //start from tail
    {
        Node<T> *next = this->tail;
        
        for (int i = 0; i < Size - index - 2; i++)
        {
            next = next->pPrev;
        }
        
        Node<T> *previous = next->pPrev->pPrev;
        next->pPrev = previous;
        previous->pNext = next;
    }
    
    Size--;
}

template<typename T>
void DoublyList<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
T & DoublyList<T>::operator[](const int index)
{
    if (index <= Size / 2)
    {
        int counter = 0;
        Node<T> *current = this->head;
        
        while (current != nullptr) //while element is not last in the list
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
        
        return current->data; //return null if index is out of range
    }
    else
    {
        int counter = 0;
        Node<T> *current = this->tail;
        
        while (current != nullptr)
        {
            if (counter == Size - index - 1)
            {
                return current->data;
            }
            current = current->pPrev;
            counter++;
        }
        
        return current->data;
    }
}
