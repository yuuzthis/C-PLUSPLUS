#ifndef CALCULATOR_CPP
#define CALCULATOR_CPP

#include "LinkedList.h"

// Default constructor
template <typename T>
LinkedList<T>::LinkedList() : mSize(0), mHead(nullptr) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear(); // Call the clear function to free up memory
}

// Clear the linked list by deleting all nodes
template <typename T>
void LinkedList<T>::clear()
{
    while (mHead != nullptr)
    {
        Node<T> *temp = mHead; // Store the current head
        mHead = mHead->mNext;  // Move the head to the next node
        delete temp;           // Delete the previous head
    }
    mSize = 0; // Reset size to 0 after clearing the list
}

// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &original) : mSize(0), mHead(nullptr)
{
    copyFrom(original); // Copy all elements from the original list
}

// Copy assignment operator
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &original)
{
    if (this != &original)
    {                       // Prevent self-assignment
        clear();            // Clear the current list
        copyFrom(original); // Copy from the original list
    }
    return *this;
}

// Copy all elements from another linked list
template <typename T>
void LinkedList<T>::copyFrom(const LinkedList<T> &other)
{
    Node<T> *current = other.mHead;
    while (current != nullptr)
    {                        // Traverse the original list
        add(current->mData); // Add each element to the new list
        current = current->mNext;
    }
}

// Move constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&temporary)
    : mSize(temporary.mSize), mHead(temporary.mHead)
{
    temporary.mSize = 0;       // Reset the temporary list's size
    temporary.mHead = nullptr; // Reset the temporary list's head
}

// Move assignment operator
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&temporary)
{
    if (this != &temporary)
    {            // Prevent self-assignment
        clear(); // Clear the current list

        // Steal resources from the temporary list
        mSize = temporary.mSize;
        mHead = temporary.mHead;

        // Reset the temporary list
        temporary.mSize = 0;
        temporary.mHead = nullptr;
    }
    return *this;
}

// Add a new element to the end of the list
template <typename T>
void LinkedList<T>::add(const T &data)
{
    Node<T> *newNode = new Node<T>(data); // Create a new node
    if (mHead == nullptr)
    {
        mHead = newNode; // If the list is empty, make this node the head
    }
    else
    {
        Node<T> *current = mHead;
        while (current->mNext != nullptr)
        { // Traverse to the last node
            current = current->mNext;
        }
        current->mNext = newNode; // Attach the new node at the end
    }
    ++mSize; // Increment the size of the list
}

// Get the element at a specific index
template <typename T>
T *LinkedList<T>::get(std::size_t index)
{
    if (index >= mSize)
    {
        return nullptr; // Return nullptr if index is out of bounds
    }

    Node<T> *current = mHead;
    for (std::size_t i = 0; i < index; ++i)
    {
        current = current->mNext; // Traverse to the desired index
    }
    return &current->mData; // Return a pointer to the element at the index
}

// Remove the element at a specific index
template <typename T>
void LinkedList<T>::remove(std::size_t index)
{
    if (index >= mSize)
    {
        return; // Do nothing if index is out of bounds
    }

    Node<T> *current = mHead;

    if (index == 0)
    {
        // Special case for removing the head of the list
        mHead = mHead->mNext;
        delete current; // Delete the old head
    }
    else
    {
        Node<T> *previous = nullptr;
        for (std::size_t i = 0; i < index; ++i)
        {
            previous = current;
            current = current->mNext; // Traverse to the node to be removed
        }
        previous->mNext = current->mNext; // Bypass the node to be removed
        delete current;                   // Delete the node
    }

    --mSize; // Decrement the size of the list
}

#endif
