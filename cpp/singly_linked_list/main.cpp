#include "SinglyLinked.hpp"
#include "SinglyLinked.cpp"
#include <iostream>

int main() {
    // Test Node copy constructor
    std::cout << "Testing Node Copy Constructor:" << std::endl;
    Node<int> a(10);
    a.next = std::make_shared<Node<int>>(20);
    Node<int> b = a; // Invoke copy constructor
    std::cout << "Original Node: Value = " << a.val << ", Next Value = " << (a.next ? a.next->val : -1) << std::endl;
    std::cout << "Copied Node: Value = " << b.val << ", Next Value = " << (b.next ? b.next->val : -1) << std::endl;

    // Modify the copied node to check independence
    b.next->val = 30;
    std::cout << "After Modifying Copied Node:" << std::endl;
    std::cout << "Original Node: Value = " << a.val << ", Next Value = " << (a.next ? a.next->val : -1) << std::endl;
    std::cout << "Copied Node: Value = " << b.val << ", Next Value = " << (b.next ? b.next->val : -1) << std::endl;

    // Test SinglyLinkedList copy constructor
    std::cout << "\nTesting SinglyLinkedList Copy Constructor:" << std::endl;
    SinglyLinkedList<int> list;

    // Insert elements
    list.insert_at_head(10);
    list.insert_at_head(20);
    list.insert_at_end(30);

    // Display the original list
    std::cout << "Original List: " << list << std::endl;

    // Copy the list
    SinglyLinkedList<int> copiedList = list; // Invoke copy constructor
    std::cout << "Copied List: " << copiedList << std::endl;

    // Modify the original list to check independence
    list.insert_at_head(40);
    list.insert_at_end(50);
    std::cout << "Modified Original List: " << list << std::endl;
    std::cout << "Unchanged Copied List: " << copiedList << std::endl;

    return 0;
}
