//
//  binaryTree.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 10/5/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename T>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    
    void insert(T key);             //insert value to a tree
    T search(T key);                //search for value in a tree -> return data if find and return NULL if not
    void destroy_tree();            //delete all elements in a tree
    void inorder_print();           //print a tree left->top->right
    void postorder_print();         //     -//-    left->right->top
    void preorder_print();          //     -//-    top->left->rigt
    void size() { return Size; };   //return size of binary tree
    
private:
    template<typename TN>
    struct Node
    {
    public:
        TN data;
        Node *pLeft;
        Node *pRight;
        
        Node<TN>(TN data = TN(), Node *pLeft = nullptr, Node *pRight = nullptr)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
    };
    
    void insert(T key, Node<T> *leaf);       //insert value into a leaf
    T search(T key, Node<T> *leaf);          //search for value in a leaf
    void destroy_tree(Node<T> *leaf);        //destroy a tree from a leaf
    void inorder_print(Node<T> *leaf);       //print tree from a leaf left->top->right
    void postorder_print(Node<T> *leaf);     //        -//-           left->right->top
    void preorder_print(Node<T> *leaf);      //        -//-           top->left->right
    
    int Size;
    Node<T> *root;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
    Size = 0;
    root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    destroy_tree();
}

template<typename T>
void BinaryTree<T>::insert(T key, Node<T> *leaf)
{
    if (key < leaf->data)
    {
        if (leaf->pLeft != nullptr)
        {
            insert(key, leaf->pLeft);
        }
        else
        {
            leaf->pLeft = new Node<T>(key);
        }
    }
    else if (key >= leaf->data)
    {
        if (leaf->pRight != nullptr)
        {
            insert(key, leaf->pRight);
        }
        else
        {
            leaf->pRight = new Node<T>(key);
        }
    }
}

template<typename T>
void BinaryTree<T>::insert(T key)
{
    if (root != nullptr)
    {
        insert(key, root);
    }
    else
    {
        root = new Node<T>(key);
    }
    Size++;
}

template<typename T>
T BinaryTree<T>::search(T key, Node<T> *leaf)
{
    if (leaf != nullptr)
    {
        if (key == leaf->data)
        {
            return leaf->data;
        }
        if (key < leaf->data)
        {
            return search(key, leaf->pLeft);
        }
        else
        {
            return search(key, leaf->pRight);
        }
    }
    else
    {
        return NULL;
    }
}

template<typename T>
T BinaryTree<T>::search(T key)
{
    return search(key, root);
}

template<typename T>
void BinaryTree<T>::destroy_tree(Node<T> *leaf)
{
    if (leaf != nullptr)
    {
        destroy_tree(leaf->pLeft);
        destroy_tree(leaf->pRight);
        delete leaf;
        Size--;
    }
}

template<typename T>
void BinaryTree<T>::destroy_tree()
{
    destroy_tree(root);
}

template <typename T>
void BinaryTree<T>::inorder_print(Node<T> *leaf)
{
    if (leaf != nullptr)
    {
        inorder_print(leaf->pLeft);
        std::cout << leaf->data << ";";
        inorder_print(leaf->pRight);
    }
}

template<typename T>
void BinaryTree<T>::inorder_print()
{
    inorder_print(root);
    std::cout << "\n";
}

template <typename T>
void BinaryTree<T>::postorder_print(Node<T> *leaf)
{
    if (leaf != nullptr)
    {
        postorder_print(leaf->pLeft);
        postorder_print(leaf->pRight);
        std::cout << leaf->data << ";";
    }
}

template<typename T>
void BinaryTree<T>::postorder_print()
{
    postorder_print(root);
    std::cout << "\n";
}

template <typename T>
void BinaryTree<T>::preorder_print(Node<T> *leaf)
{
    if (leaf != nullptr)
    {
        std::cout << leaf->data << ";";
        preorder_print(leaf->pLeft);
        preorder_print(leaf->pRight);
    }
}

template<typename T>
void BinaryTree<T>::preorder_print()
{
    preorder_print(root);
    std::cout << "\n";
}
