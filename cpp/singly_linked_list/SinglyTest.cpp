#include <iostream>
#include <sstream>
#include <cassert>
#include "SinglyLinked.hpp"
#include "SinglyLinked.cpp"

int main() {
    // Test default constructor and size
    SinglyLinkedList<int> list;
    assert(list.get_size() == 0);

    // Test insert_at_head
    list.insert_at_head(10);
    assert(list.get_size() == 1);
    assert(list.get_head()->val == 10);

    list.insert_at_head(5);
    assert(list.get_size() == 2);
    assert(list.get_head()->val == 5);

    // Test insert_at_end
    list.insert_at_end(15);
    assert(list.get_size() == 3);
    assert(list.get_head()->next->next->val == 15);

    // Test insert_at_index
    list.insert_at_index(1, 7);
    assert(list.get_size() == 4);
    assert(list.get_head()->next->val == 7);

    // Test get_size
    assert(list.get_size() == 4);

    // Test search_by_value
    auto node = list.search_by_value(7);
    assert(node != nullptr && node->val == 7);

    node = list.search_by_value(99);
    assert(node == nullptr);

    // Test delete_at_head
    list.delete_at_head();
    assert(list.get_size() == 3);
    assert(list.get_head()->val == 7);

    // Test delete_at_end
    list.delete_at_end();
    assert(list.get_size() == 2);
    assert(list.get_head()->next->val == 10);

    // Test delete_at_index
    list.delete_at_index(0);
    assert(list.get_size() == 1);
    assert(list.get_head()->val == 10);

    list.delete_at_index(0); // Delete last remaining element
    assert(list.get_size() == 0);

    // Test exception handling for delete on empty list
    try {
        list.delete_at_head();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        assert(true);
    }

    // Test copy constructor
    list.insert_at_end(20);
    list.insert_at_end(30);
    SinglyLinkedList<int> copiedList(list);
    assert(copiedList.get_size() == list.get_size());
    assert(copiedList.get_head() != list.get_head());
    assert(copiedList.get_head()->val == list.get_head()->val);

    // Modify the original and ensure copy remains unchanged
    list.insert_at_head(10);
    assert(list.get_size() == 3);
    assert(copiedList.get_size() == 2);

    // Test output operator
    std::ostringstream oss;
    oss << copiedList;
    assert(oss.str() == "20 -> 30 -> nullptr");

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
