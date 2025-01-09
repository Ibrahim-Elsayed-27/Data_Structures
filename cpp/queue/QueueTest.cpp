#include <iostream>
#include <cassert>
#include <sstream>
#include "Queue.hpp"
#include "Queue.cpp"

void testQueueEnqueue() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    assert(q.peek() == 10); // First element remains at the front
    assert(q.isEmpty() == false);
    std::cout << "testQueueEnqueue passed!" << std::endl;
}

void testQueueDequeue() {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    assert(q.dequeue() == 5); // Remove the first element
    assert(q.dequeue() == 10); // Remove the next element
    assert(q.dequeue() == 15); // Remove the last element

    assert(q.isEmpty() == true); // Queue should be empty

    // Test underflow exception
    try {
        q.dequeue();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception as expected: " << e.what() << std::endl;
    }

    std::cout << "testQueueDequeue passed!" << std::endl;
}

void testQueuePeek() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);

    assert(q.peek() == 1); // Peek the front element

    q.dequeue();
    assert(q.peek() == 2); // Peek updates after dequeuing

    // Test underflow exception
    q.dequeue();
    try {
        q.peek();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception as expected: " << e.what() << std::endl;
    }

    std::cout << "testQueuePeek passed!" << std::endl;
}

void testQueueIsEmpty() {
    Queue<int> q;

    assert(q.isEmpty() == true); // New queue is empty

    q.enqueue(42);
    assert(q.isEmpty() == false); // Not empty after enqueue

    q.dequeue();
    assert(q.isEmpty() == true); // Empty after dequeuing all elements

    std::cout << "testQueueIsEmpty passed!" << std::endl;
}

void testQueueCopyConstructor() {
    Queue<int> q1;
    q1.enqueue(100);
    q1.enqueue(200);

    Queue<int> q2(q1); // Copy constructor

    assert(q2.dequeue() == 100);
    assert(q2.dequeue() == 200);
    assert(q2.isEmpty());

    // Ensure original queue is unchanged
    assert(q1.peek() == 100);
    std::cout << "testQueueCopyConstructor passed!" << std::endl;
}

void testQueueMoveConstructor() {
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);

    Queue<int> q2(std::move(q1)); // Move constructor

    assert(q2.dequeue() == 10);
    assert(q2.dequeue() == 20);
    assert(q2.isEmpty());

    // Original queue should be empty
    assert(q1.isEmpty());

    std::cout << "testQueueMoveConstructor passed!" << std::endl;
}

void testQueuePrintOperator() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::ostringstream oss;
    oss << q;

    assert(oss.str() == "1 -> 2 -> 3 -> nullptr");

    std::cout << "Queue contents: " << q << std::endl;
    std::cout << "testQueuePrintOperator passed!" << std::endl;
}

int main() {
    testQueueEnqueue();
    testQueueDequeue();
    testQueuePeek();
    testQueueIsEmpty();
    testQueueCopyConstructor();
    testQueueMoveConstructor();
    testQueuePrintOperator();

    std::cout << "All queue tests passed!" << std::endl;
    return 0;
}
