//
//  map.cpp
//  myDynamicDataStructures
//
//  Created by Roman on 10/5/19.
//  Copyright © 2019 Roman. All rights reserved.
//

#include <stdio.h>
#include <iostream>

template<typename TK, typename TV>
class MapNode
{
public:
    TV value;
    TK key;
    MapNode *pLeft;
    MapNode *pRight;
    
    MapNode<TK, TV>(TK key = TK(), TV value = TV(), MapNode *pLeft = nullptr, MapNode *pRight = nullptr)
    {
        this->key = key;
        this->value = value;
        this->pLeft = pLeft;
        this->pRight = pRight;
    }
};

template<typename K, typename V>
class Map
{
public:
    Map();
    ~Map();
    
    void insert(K key, V value);                    //insert key:value to a map (note: key should be unique)
    MapNode<K, V> searchByKey(K key);               //search for value in a map by key
    void destroy_map();                             //delete all elements in a map
    void printKeys();                               //print map  Keys top->left->rigt
    void printValues();                             //   -//-    Values top->left->rigt
    void printKeyValues();                          //   -//-    Key:Values top->left->right
    void size() { return Size; };                   //return size of a map
    
private:
    void insert(K key, V value, MapNode<K, V> *leaf);        //insert value into a leaf
    MapNode<K, V> searchByKey(K key, MapNode<K, V> *leaf);   //search for value in a leaf
    void destroy_map(MapNode<K, V> *leaf);                   //destroy map from a leaf
    void printKeys(MapNode<K, V> *leaf);                     //print map  Keys top->left->rigt
    void printValues(MapNode<K, V> *leaf);                   //   -//-    Values top->left->rigt
    void printKeyValues(MapNode<K, V> *leaf);                //   -//-    Key:Values top->left->right
    
    int Size;
    MapNode<K, V> *root;
};

template<typename K, typename V>
Map<K, V>::Map()
{
    Size = 0;
    root = nullptr;
}

template<typename K, typename V>
Map<K, V>::~Map()
{
    destroy_map();
}

template<typename K, typename V>
void Map<K, V>::insert(K key, V value, MapNode<K, V> *leaf)
{
    if (searchByKey(key, root).key != NULL)
    {
        throw std::invalid_argument("key is not unique");
    }
    
    if (key < leaf->key)
    {
        if (leaf->pLeft != nullptr)
        {
            insert(key, value, leaf->pLeft);
        }
        else
        {
            leaf->pLeft = new MapNode<K, V>(key, value);
        }
    }
    else if (key >= leaf->key)
    {
        if (leaf->pRight != nullptr)
        {
            insert(key, value, leaf->pRight);
        }
        else
        {
            leaf->pRight = new MapNode<K, V>(key, value);
        }
    }
}

template<typename K, typename V>
void Map<K, V>::insert(K key, V value)
{
    if (root != nullptr)
    {
        insert(key, value, root);
    }
    else
    {
        root = new MapNode<K, V>(key, value);
    }
    Size++;
}

template<typename K, typename V>
MapNode<K,V> Map<K, V>::searchByKey(K key, MapNode<K, V> *leaf)
{
    if (leaf != nullptr)
    {
        if (key == leaf->key)
        {
            return *leaf;
        }
        if (key < leaf->key)
        {
            return searchByKey(key, leaf->pLeft);
        }
        else
        {
            return searchByKey(key, leaf->pRight);
        }
    }
    else
    {
        return NULL;
    }
}

template<typename K, typename V>
MapNode<K, V> Map<K, V>::searchByKey(K key)
{
    return searchByKey(key, root);
}

template<typename K, typename V>
void Map<K, V>::destroy_map(MapNode<K, V> *leaf)
{
    if (leaf != nullptr)
    {
        destroy_map(leaf->pLeft);
        destroy_map(leaf->pRight);
        delete leaf;
        Size--;
    }
}

template<typename K, typename V>
void Map<K, V>::destroy_map()
{
    destroy_map(root);
}

template<typename K, typename V>
void Map<K, V>::printKeys(MapNode<K, V> *leaf)
{
    if (leaf != nullptr)
    {
        std::cout << leaf->key << ";";
        printKeys(leaf->pLeft);
        printKeys(leaf->pRight);
    }
}

template<typename K, typename V>
void Map<K, V>::printKeys()
{
    printKeys(root);
    std::cout << "\n";
}

template<typename K, typename V>
void Map<K, V>::printValues(MapNode<K, V> *leaf)
{
    if (leaf != nullptr)
    {
        std::cout << leaf->value << ";";
        printValues(leaf->pLeft);
        printValues(leaf->pRight);
    }
}

template<typename K, typename V>
void Map<K, V>::printValues()
{
    printValues(root);
    std::cout << "\n";
}

template<typename K, typename V>
void Map<K, V>::printKeyValues(MapNode<K, V> *leaf)
{
    if (leaf != nullptr)
    {
        std::cout << leaf->key << ":" << leaf->value << ";";
        printKeyValues(leaf->pLeft);
        printKeyValues(leaf->pRight);
    }
}

template<typename K, typename V>
void Map<K, V>::printKeyValues()
{
    printKeyValues(root);
    std::cout << "\n";
}
