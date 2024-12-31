# Singly Linked List Implementation

This project provides a robust implementation of a **Singly Linked List** in C++ using modern features like **smart pointers** to ensure safe memory management. It includes both the list and node implementations, along with a test suite to validate its functionality.

## Features

### 1. **Node Class**
- Represents an individual element in the list.
- Uses `std::shared_ptr` for safe and efficient memory management.
- Contains:
  - `val`: The value of the node.
  - `next`: Pointer to the next node in the list.

### 2. **SinglyLinkedList Class**
A template-based implementation of a singly linked list supporting the following operations:

#### Basic Operations:
- **Insertions**:
  - At the head.
  - At the end.
  - At a specific index.
- **Deletions**:
  - At the head.
  - At the end.
  - At a specific index.
  
#### Utility Functions:
- Search for a node by value.
- Get the current size of the list.

#### Additional Features:
- Deep copy constructor for duplicating lists without shared memory references.
- Overloaded `<<` operator for easy list printing in the format:  
  ```
  10 -> 20 -> 30 -> nullptr
  ```

### 3. **Test Suite**
- The `SinglyTest.cpp` file contains extensive tests using `assert` to verify:
  - Proper functioning of all operations (insertions, deletions, search, etc.).
  - Deep copy correctness (no shared memory between copied lists).
  - List integrity after modifications.

## Implementation Details

### Smart Pointers
The project uses `std::shared_ptr` for:
- Automatic memory management.
- Avoiding manual `delete` calls.
- Preventing memory leaks and dangling pointers.

### Template-Based Design
- The `SinglyLinkedList` class is templated, allowing it to store any data type (`int`, `float`, custom objects, etc.).

### Copy Constructor
- Ensures a **deep copy**, creating independent nodes for the new list. Modifications to one list do not affect the other.

## File Structure

- `SinglyLinked.hpp`: Header file containing class definitions for `Node` and `SinglyLinkedList`.
- `SinglyLinked.cpp`: Source file with method implementations for `Node` and `SinglyLinkedList`.
- `main.cpp`: Contains the main function for demonstrating the list's functionality.
- `SinglyTest.cpp`: Comprehensive test suite for verifying the correctness of the implementation.
- `Makefile`: Automates compilation for both the main program and test suite.
- `README.md`: Project documentation (this file).

## Compilation and Usage

### Prerequisites
- GCC with C++17 support.
- A terminal or command-line interface.

### Compilation
Use the provided `Makefile` to compile the main program or test suite:

1. **Compile Main Program**:
   ```bash
   make
   ```
   This generates an executable named `SinglyMain`.

2. **Compile Test Suite**:
   ```bash
   make test
   ```
   This generates an executable named `SinglyTest`.

3. **Clean Build Artifacts**:
   ```bash
   make clean
   ```

### Running
- **Main Program**:
  ```bash
  ./SinglyMain
  ```

- **Test Suite**:
  ```bash
  ./SinglyTest
  ```
  If all tests pass, it will display:
  ```
  All tests passed!
  ```

## Example Usage

### Inserting and Printing
```cpp
SinglyLinkedList<int> list;
list.insert_at_end(10);
list.insert_at_end(20);
list.insert_at_head(5);
std::cout << list; // Outputs: 5 -> 10 -> 20 -> nullptr
```

### Searching
```cpp
auto node = list.search_by_value(10);
if (node) {
    std::cout << "Found: " << node->val << std::endl;
} else {
    std::cout << "Not found!" << std::endl;
}
```

### Deep Copy
```cpp
SinglyLinkedList<int> list2 = list; // Creates a deep copy
list.insert_at_end(30);
std::cout << list;  // Outputs: 5 -> 10 -> 20 -> 30 -> nullptr
std::cout << list2; // Outputs: 5 -> 10 -> 20 -> nullptr
```

## Key Considerations
- **Efficiency**: Designed with performance in mind, avoiding unnecessary computations.
- **Safety**: Uses smart pointers to minimize memory-related bugs.
- **Scalability**: Template-based to handle various data types.

