#include <iostream>
#include "Queue.hpp"
#include "Queue.cpp"

int main() {
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue: " << queue << std::endl; // Outputs: 1 -> 2 -> 3 -> nullptr

    // Dequeue an element
    std::cout << "Dequeued: " << queue.dequeue() << std::endl; // Outputs: Dequeued: 1

    // Peek at the front element
    std::cout << "Front element: " << queue.peek() << std::endl; // Outputs: Front element: 2

}