# Queue Implementation

This project provides a comprehensive implementation of a **generic queue data structure** in C++ using a **singly linked list**. Designed for flexibility and efficiency, the implementation employs modern C++ features like templates, exception handling, and robust memory management to ensure reliable performance.

---

## Features

### 1. Core Queue Operations
- **Enqueue**: Add an element to the rear of the queue.
- **Dequeue**: Remove and return the front element of the queue.
- **Peek**: View the front element without removing it.
- **isEmpty**: Check whether the queue is empty.

### 2. Memory Management
- **Copy Constructor**: Enables creating a new queue as a deep copy of an existing one.
- **Move Constructor**: Transfers ownership of resources efficiently, leaving the source queue empty.
- **Smart Pointers**: Ensures safe and automatic memory management.

### 3. Exception Handling
- Handles queue underflow gracefully by throwing exceptions when `dequeue` or `peek` is called on an empty queue.

### 4. Templated Design
- Supports storage of any data type (`int`, `float`, custom objects, etc.).

### 5. Overloaded `<<` Operator
- Provides an intuitive way to display queue contents in the format:
  ```
  10 -> 20 -> 30 -> nullptr
  ```

---

## Classes Overview

### `Node<T>`
A node in the singly linked list backing the queue.  
- **Attributes**: 
  - `val`: The value of the node.
  - `next`: Pointer to the next node.

### `Queue<T>`
The main queue class built on a singly linked list.  
- **Operations**:
  - Queue-specific methods (`enqueue`, `dequeue`, `peek`, `isEmpty`).
  - Copy and move constructors for efficient memory handling.
- Overloaded `<<` operator for printing queue contents.

---

## File Structure

- `Queue.hpp`: Contains the definitions of the `Node` and `Queue` classes.
- `QueueTest.cpp`: Implements a test suite to validate queue operations.
- `main.cpp`: Demonstrates queue functionality through example code.
- `Makefile`: Automates compilation and testing tasks.
- `README.md`: Project documentation (this file).

---

## Compilation and Usage

### Prerequisites
- GCC or Clang with C++17 support.
- A terminal or command-line interface.

### Compilation
1. Compile the main application:
   ```bash
   make
   ```
   This creates an executable named `QueueMain`.

2. Compile the test suite:
   ```bash
   make test
   ```
   This creates an executable named `QueueTest`.

3. Clean up build artifacts:
   ```bash
   make clean
   ```

### Execution
- Run the main program:
  ```bash
  ./QueueMain
  ```
- Run the test suite:
  ```bash
  ./QueueTest
  ```
  If all tests pass, it displays:
  ```
  All Queue tests passed!
  ```

---

## Example Usage

### Queue Operations
```cpp
#include <iostream>
#include "Queue.hpp"

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

    return 0;
}
```

---

## Testing

### Key Test Cases
- Validate all core operations (`enqueue`, `dequeue`, `peek`, `isEmpty`).
- Verify deep copy functionality (independent queues with no shared resources).
- Confirm move semantics (ownership transfer and source reset).
- Test exception handling for queue underflow.

### Running Tests
Compile and execute the test suite as follows:
```bash
make test
./QueueTest
```