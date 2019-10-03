//
//  singleLinkedList.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 9/25/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class List
{
public:
    List();
    ~List();
    
    void push_back(T data);             //add element at the end of a list
    void push_front(T data);            //add element at the beginning of the list
    void pop_back();                    //remove element from the end of a list
    void pop_front();                   //remove element at the beginning of the list
    void insert(T value, int index);    //insert value at index
    void removeAt(int index);           //remove value at index
    void clear();                       //clear list
    void print();                       //print list
    int getSize() { return Size; };     //get list size
    T& operator[](const int index);     //get element at index (return ref to element, so we can change data)
    
private:
    template<typename TN>           //create template to use different types to store data
    class Node
    {
    public:                         //use only public because only we have access to that class under private section
        Node *pNext;                //pointer to the next element
        TN data;                    //data that stored
        
        Node(TN data = TN(), Node *pNext = nullptr) //nullptr by default (so it's last element by default); TN() - initialize variable with TN type
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    
    int Size;       //list size
    Node<T> *head;  //pointer to 1st element
    
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();        //clear all created data
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)    //check is list blank
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        
        while (current->pNext != nullptr)   // looking for the last element in a list
        {
            current = current->pNext;
        }
        
        current->pNext = new Node<T>(data); //create new object at the end of a list and set pointer to it from the previous element
    }
    
    Size++; //increase size
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head); //new element is  a head and he points to previous head
    Size++;
}

template<typename T>
T & List<T>::operator[](const int index)
{
    int counter = 0;
    
    Node<T> *current = this->head; //tmp variable to store current pointers; equals to head cause we start to iterate from the 1st element in a list
    
    while (current != nullptr) //while element is not last in a list
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

template<typename T>
void List<T>::insert(T value, int index)
{
    if (index > Size - 1 || index < 0)
    {
        throw std::out_of_range("position is out of range");
    }
    
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T> *previous = this->head; //need this to set his pointer to a new element
        
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        
        previous->pNext = new Node<T>(value, previous->pNext); //will point to the same element that previous element pointed
        Size++;
    }
    
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index > Size - 1 || index < 0)
    {
        throw std::out_of_range("can't remove element fron an empty stack");
    }
    
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head; //need this to set his pointer to another element
        
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        
        Node<T> *current = previous->pNext;
        previous->pNext = current->pNext;
        delete current;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}

template<typename T>
void List<T>::pop_front()
{
    if (Size)
    {
        Node<T> *temp = head;
        head = head->pNext; //set new head
        delete temp;
        Size--;
    }
    else
    {
        throw std::out_of_range("can't remove element from an empty list");
    }
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::print()
{
    Node<T> *current = this->head;
    
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
}
