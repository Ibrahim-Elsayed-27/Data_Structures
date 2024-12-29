#include <iostream>
#include "Stack.hpp"
#include "Stack.cpp"

int main() {
    Stack<int> stack;

    // Test: Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack after pushing 10, 20, 30: " << stack << std::endl;

    // Test: Peek the top element
    std::cout << "Top element (peek): " << stack.peek() << std::endl;

    // Test: Pop elements
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Stack after popping: " << stack << std::endl;

    // Test: Push more elements
    stack.push(40);
    stack.push(50);
    std::cout << "Stack after pushing 40, 50: " << stack << std::endl;

    // Test: Empty the stack
    while (!stack.isEmpty()) {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }
    std::cout << "Stack after emptying: " << stack << std::endl;

    // Test: Pop from an empty stack (should throw an error)
    try {
        stack.pop();
    } catch (const std::underflow_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
