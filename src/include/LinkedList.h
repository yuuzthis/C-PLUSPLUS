#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef> // std::size_t
#include <iostream>

namespace LinkedList
{
    // Template struct representing a Node in the LinkedList
    template <typename T>
    struct Node
    {
        T mData;        // Data stored in the node
        Node<T> *mNext; // Pointer to the next node

        // Constructor to initialize the node with data and optionally a next node
        Node(const T &data, Node<T> *next = nullptr)
            : mData(data), mNext(next) {}
    };

    // Template class for a LinkedList data structure
    template <typename T>
    class LinkedList
    {
    private:
        std::size_t mSize; // Number of elements in the list
        Node<T> *mHead;    // Pointer to the first node in the list

    public:
        LinkedList();  // Constructor
        ~LinkedList(); // Destructor

        LinkedList(const LinkedList<T> &original);               // Copy constructor
        LinkedList<T> &operator=(const LinkedList<T> &original); // Copy assignment operator

        LinkedList(LinkedList<T> &&temporary);               // Move constructor
        LinkedList<T> &operator=(LinkedList<T> &&temporary); // Move assignment operator

        void add(const T &data);        // Add an element to the end of the list
        T *get(std::size_t index);      // Get an element at a specific index
        void remove(std::size_t index); // Remove an element at a specific index

    private:
        void clear();                              // Clear all nodes in the list
        void copyFrom(const LinkedList<T> &other); // Copy elements from another list
    };

#include "LinkedList.tpp" // Include the implementation in a separate file
}
#endif
