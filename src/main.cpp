#include "LinkedList.h"
#include <iostream>

int main() {
    // Create a linked list of integers
    LinkedList<int> list;

    // Add elements to the list
    list.add(10);
    list.add(20);
    list.add(30);

    // Retrieve and print elements in the list
    std::cout << "Current list: ";
    for (std::size_t i = 0; i < 3; ++i) {
        int* value = list.get(i);  // Get the element at index i
        if (value != nullptr) {
            std::cout << *value << " ";  // Print the value if it's not null
        }
    }
    std::cout << std::endl;

    // Remove the element at index 1 (which is the value 20)
    list.remove(1);
    std::cout << "List after removing the element at index 1: ";
    for (std::size_t i = 0; i < 2; ++i) {
        int* value = list.get(i);  // Get the element at index i
        if (value != nullptr) {
            std::cout << *value << " ";  // Print the value if it's not null
        }
    }
    std::cout << std::endl;

    // Test the copy constructor
    LinkedList<int> copiedList = list;  // Create a copy of the list
    std::cout << "Copied list: ";
    for (std::size_t i = 0; i < 2; ++i) {
        int* value = copiedList.get(i);  // Get the element from the copied list
        if (value != nullptr) {
            std::cout << *value << " ";  // Print the value if it's not null
        }
    }
    std::cout << std::endl;

    // Test the move constructor
    LinkedList<int> movedList = std::move(list);  // Move the original list to a new one
    std::cout << "List after moving: ";
    for (std::size_t i = 0; i < 2; ++i) {
        int* value = movedList.get(i);  // Get the element from the moved list
        if (value != nullptr) {
            std::cout << *value << " ";  // Print the value if it's not null
        }
    }
    std::cout << std::endl;

    return 0;
}
