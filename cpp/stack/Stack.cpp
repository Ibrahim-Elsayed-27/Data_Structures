#include "Stack.hpp"


// Constructor
template <typename T>
Node<T>::Node(const T& value) : val(value), next(nullptr) {}





// Get head
template <typename T>
Node<T>* SinglyLinkedList<T>::get_head(){
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return head.get();
}

// Insert at beginning
template <typename T>
void SinglyLinkedList<T>::insert_at_head(const T& value){
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(value);
    temp->next = head;
    head = temp;
    size++;
}


// Insert at End
template <typename T>
void SinglyLinkedList<T>::insert_at_end(const T& value){
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(value);

    // Check if the list is empty
    if (head == nullptr) {
        head = temp; // The new node becomes the head
    } else {
        // Traverse to the end of the list
        std::shared_ptr<Node<T>> iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = temp; // Append the new node at the end
    }
    size++;
}


// Insert at index
template <typename T>
void SinglyLinkedList<T>::insert_at_index(int index, const T& value){
    if (index < 0 || index > size) {
        throw std::out_of_range("Index is out of range");
    }
    std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(value);
    if (index == 0) {
        temp->next = head;
        head = temp;
    } else {
        // Traverse to the node just before the target index
        std::shared_ptr<Node<T>> iter = head;
        for (int i = 0; i < index - 1; ++i) {
            iter = iter->next;
        }
        // Insert the new node
        temp->next = iter->next;
        iter->next = temp;
    }
    size++;
    
}


// Deletion at beginning
template <typename T>
void SinglyLinkedList<T>::delete_at_head() {
    if (head != nullptr) {
        head = head->next; // Move head to the next node
        size--;
    } else {
        throw std::underflow_error("List is empty. Cannot delete at head.");
    }
}


// Deletion at End
template <typename T>
void SinglyLinkedList<T>::delete_at_end() {
    if (head == nullptr) {
        throw std::underflow_error("List is empty. Cannot delete at end.");
    }
    

    if (size == 1) {
        // Handle single-element list
        head = nullptr;
    } else {
        // Traverse to the second-to-last node
        std::shared_ptr<Node<T>> iter = head;
        while (iter->next->next != nullptr) {
            iter = iter->next;
        }
        iter->next = nullptr; // Remove the last node
    }
    size--;
}



// Delete at index
template <typename T>
void SinglyLinkedList<T>::delete_at_index(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    if (index == 0) {
        delete_at_head(); // Use existing method
        return;
    }

    std::shared_ptr<Node<T>> iter = head;
    for (int i = 0; i < index - 1; ++i) {
        iter = iter->next;
    }
    iter->next = iter->next->next; // Bypass the node at the index
    size--;
}


// Search by value
template <typename T>
std::shared_ptr<Node<T>> SinglyLinkedList<T>::search_by_value(const T& value) {
    std::shared_ptr<Node<T>> iter = head;
    while (iter != nullptr) {
        if (iter->val == value) {
            return iter; // Node found
        }
        iter = iter->next;
    }
    return nullptr; // Value not found
}


// Getter for size of the list
template <typename T>
int SinglyLinkedList<T>::get_size(){
    return size;
}


// Overload << operator for printing the list
template <typename U>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& list){
    std::shared_ptr<Node<U>> iter = list.head;
    while (iter != nullptr) {
        os << iter->val << " -> ";
        iter = iter->next;
    }
    os << "nullptr"; // Indicate the end of the list
    return os;
}

template <typename T>
void Stack<T>::push(const T& value){
    stack_list.insert_at_head(value);
}

template <typename T>
T Stack<T>::pop(){
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot pop.");
    }
    T top = peek();
    stack_list.delete_at_head();
    return top;
}

template <typename T>
T Stack<T>::peek(){
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty. Cannot peek.");
    }
    return stack_list.get_head()->val;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return (stack_list.get_size() == 0);
}
// Overload << operator for printing the stack
template <typename U>
std::ostream& operator<<(std::ostream& os, const Stack<U>& stack) {
    os << stack.stack_list; // Delegate to SinglyLinkedList's operator<<
    return os;
}

