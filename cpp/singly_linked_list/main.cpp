#include "SinglyLinked.hpp"
#include "SinglyLinked.cpp"
#include <iostream>

int main() {
    // Create a singly linked list of integers
    SinglyLinkedList<int> list;

    // Insert elements
    list.insert_at_head(10);
    list.insert_at_head(20);
    list.insert_at_end(30);
    list.insert_at_end(40);
    list.insert_at_index(2, 25); // Insert 25 at index 2

    // Display the list
    std::cout << "List after insertions: " << list << std::endl;

    // Delete elements
    list.delete_at_head(); // Remove 20
    list.delete_at_end();  // Remove 40
    list.delete_at_index(1); // Remove 25 at index 1

    // Display the list after deletions
    std::cout << "List after deletions: " << list << std::endl;

    // Search for a value
    int searchValue = 10;
    auto foundNode = list.search_by_value(searchValue);
    if (foundNode) {
        std::cout << "Value " << searchValue << " found in the list." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the list." << std::endl;
    }

    return 0;
}
