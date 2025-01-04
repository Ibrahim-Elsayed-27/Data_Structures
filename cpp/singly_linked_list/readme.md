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
- **Deep Copy Constructor**: Duplicates lists without shared memory references.
- **Move Constructor**: Transfers ownership of resources from one list to another.
- Overloaded `<<` operator for easy list printing in the format:  
  ``` 
  10 -> 20 -> 30 -> nullptr
  ```

### 3. **Move Constructor**
The implementation supports a move constructor to transfer ownership of resources from one list to another efficiently, avoiding deep copying. 

#### Key Benefits:
- Moves all elements from the source list to the destination list.
- Leaves the source list empty and ready for safe reuse.

#### Example:
```cpp
SinglyLinkedList<int> list1;
list1.insert_at_end(10);
list1.insert_at_end(20);

SinglyLinkedList<int> list2(std::move(list1));
// list2 now contains: 10 -> 20 -> nullptr
// list1 is empty: nullptr
```

### 4. **Test Suite**
- The `SinglyTest.cpp` file contains extensive tests using `assert` to verify:
  - Proper functioning of all operations (insertions, deletions, search, etc.).
  - Deep copy correctness (no shared memory between copied lists).
  - Move constructor behavior (ownership transfer and source list reset).
  - List integrity after modifications.

## Implementation Details

### Smart Pointers
The project uses `std::shared_ptr` for:
- Automatic memory management.
- Avoiding manual `delete` calls.
- Preventing memory leaks and dangling pointers.

### Template-Based Design
- The `SinglyLinkedList` class is templated, allowing it to store any data type (`int`, `float`, custom objects, etc.).

### Move Constructor
The move constructor transfers ownership of the linked list from one instance to another, ensuring efficient memory operations. After the move, the source list is left in an empty state.

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

### Move Constructor
```cpp
SinglyLinkedList<int> list1;
list1.insert_at_end(10);
list1.insert_at_end(20);

SinglyLinkedList<int> list2(std::move(list1));
// list2 now contains: 10 -> 20 -> nullptr
// list1 is empty: nullptr
```

## Key Considerations
- **Efficiency**: Designed with performance in mind, avoiding unnecessary computations.
- **Safety**: Uses smart pointers to minimize memory-related bugs.
- **Scalability**: Template-based to handle various data types.

