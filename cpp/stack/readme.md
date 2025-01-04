# Stack Implementation

This project provides a comprehensive implementation of a **generic stack data structure** in C++ using a **singly linked list**. Designed for flexibility and safety, the implementation leverages modern C++ features like templates and exception handling to ensure robust functionality.



## Features

### 1. Core Stack Operations
- **Push**: Add an element to the top of the stack.
- **Pop**: Remove and return the top element of the stack.
- **Peek**: View the top element without removing it.
- **isEmpty**: Check whether the stack is empty.

### 2. Memory Management
- **Copy Constructor**: Allows creating a new stack as a deep copy of an existing stack.
- **Move Constructor**: Transfers ownership of resources efficiently, leaving the source stack empty.
- **Smart Pointers**: Ensures safe and automatic memory management.

### 3. Exception Handling
- Handles stack underflow gracefully by throwing exceptions when `pop` or `peek` is called on an empty stack.

### 4. Templated Design
- Supports storage of any data type (`int`, `float`, custom objects, etc.).

### 5. Overloaded `<<` Operator
- Provides an intuitive way to display stack contents in the format:
  ```
  [Top] -> 30 -> 20 -> 10 -> nullptr
  ```



## Classes Overview

### `Node<T>`
A node in the singly linked list backing the stack.  
- **Attributes**: 
  - `val`: The node's value.
  - `next`: Pointer to the next node in the list.
- **Smart Pointer**: Uses `std::shared_ptr` for memory management.

### `SinglyLinkedList<T>`
Implements the underlying singly linked list used by the stack.  
- **Core Operations**:
  - `insert_at_head`, `delete_at_head`
  - Retrieve the size and head node.
- Overloaded `<<` operator for easy visualization of the list.

### `Stack<T>`
The main stack class built on top of `SinglyLinkedList`.  
- **Operations**:
  - Stack-specific methods (`push`, `pop`, `peek`, `isEmpty`).
  - Copy and move constructors for efficient memory handling.
- Overloaded `<<` operator for printing stack contents.



## File Structure

- `Stack.hpp`: Contains definitions for `Node`, `SinglyLinkedList`, and `Stack` classes.
- `Stack.cpp`: Implements the methods of `Stack` and its underlying list.
- `main.cpp`: Demonstrates stack functionality through sample code.
- `StackTest.cpp`: Contains a test suite for validating stack operations.
- `Makefile`: Automates compilation and testing tasks.
- `README.md`: Project documentation (this file).



## Compilation and Usage

### Prerequisites
- GCC or Clang with C++17 support.
- A terminal or command-line interface.

### Compilation
1. Compile the main application:
   ```bash
   make
   ```
   This creates an executable named `StackMain`.

2. Compile the test suite:
   ```bash
   make test
   ```
   This creates an executable named `StackTest`.

3. Clean up build artifacts:
   ```bash
   make clean
   ```

### Execution
- Run the main program:
  ```bash
  ./StackMain
  ```
- Run the test suite:
  ```bash
  ./StackTest
  ```
  If all tests pass, it displays:
  ```
  All Stack tests passed!
  ```



## Example Usage

### Stack Operations
```cpp
#include <iostream>
#include "Stack.hpp"

int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);
    std::cout << "Stack: " << stack << std::endl; // Outputs: [Top] -> 15 -> 10 -> 5 -> nullptr

    // Pop an element
    std::cout << "Popped: " << stack.pop() << std::endl; // Outputs: Popped: 15

    // Peek at the top element
    std::cout << "Top element: " << stack.peek() << std::endl; // Outputs: Top element: 10

    return 0;
}
```



## Testing

### Key Test Cases
- Validate all core operations (`push`, `pop`, `peek`, `isEmpty`).
- Verify deep copy functionality (independent stacks with no shared resources).
- Confirm move semantics (ownership transfer and source reset).
- Test exception handling for stack underflow.

### Running Tests
Compile and execute the test suite as follows:
```bash
make test
./StackTest
```

