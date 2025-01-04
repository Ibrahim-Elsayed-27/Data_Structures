#include <cassert>
#include <iostream>
#include "Stack.hpp"
#include "Stack.cpp"

void test_stack_push() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.peek() == 30); // Top of the stack should be 30
    std::cout << "test_stack_push passed!\n";
}

void test_stack_pop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.pop() == 30); // Top of the stack should be 30
    assert(stack.pop() == 20); // Top of the stack should now be 20
    assert(stack.pop() == 10); // Top of the stack should now be 10
    assert(stack.isEmpty());   // Stack should now be empty
    std::cout << "test_stack_pop passed!\n";
}

void test_stack_peek() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);

    assert(stack.peek() == 20); // Top of the stack should be 20
    stack.pop();
    assert(stack.peek() == 10); // Top of the stack should now be 10
    std::cout << "test_stack_peek passed!\n";
}

void test_stack_isEmpty() {
    Stack<int> stack;

    assert(stack.isEmpty()); // Stack should be empty initially
    stack.push(10);
    assert(!stack.isEmpty()); // Stack should not be empty after a push
    stack.pop();
    assert(stack.isEmpty()); // Stack should be empty after a pop
    std::cout << "test_stack_isEmpty passed!\n";
}

void test_stack_copy_constructor() {
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    Stack<int> stack2(stack1); // Copy constructor
    assert(stack2.pop() == 20);
    assert(stack2.pop() == 10);
    assert(stack2.isEmpty());

    // Original stack should remain unchanged
    assert(stack1.pop() == 20);
    assert(stack1.pop() == 10);
    assert(stack1.isEmpty());
    std::cout << "test_stack_copy_constructor passed!\n";
}

void test_stack_move_constructor() {
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    Stack<int> stack2(std::move(stack1)); // Move constructor
    assert(stack2.pop() == 20);
    assert(stack2.pop() == 10);
    assert(stack2.isEmpty());

    // Original stack should now be empty
    assert(stack1.isEmpty());
    std::cout << "test_stack_move_constructor passed!\n";
}

void test_stack_exceptions() {
    Stack<int> stack;

    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected underflow error on pop: " << e.what() << "\n";
    }

    try {
        stack.peek();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected underflow error on peek: " << e.what() << "\n";
    }

    std::cout << "test_stack_exceptions passed!\n";
}

int main() {
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_isEmpty();
    test_stack_copy_constructor();
    test_stack_move_constructor();
    test_stack_exceptions();

    std::cout << "All Stack tests passed!\n";
    return 0;
}
