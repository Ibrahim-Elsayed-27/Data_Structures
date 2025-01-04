#ifndef STACK_H_
#define STACK_H_

#include <stdexcept>  
#include <memory>
#include <iostream>
template <typename T> class Node{
    public:
        T val;
        std::shared_ptr<Node<T>> next;

        // Constructor
        Node(const T& value);
        // Copy Constructor
        Node(const Node<T>& other);
};


template <typename T>  class SinglyLinkedList{
    private:
        std::shared_ptr<Node<T>> head;
        int size;
    public:
        // Constructor
        SinglyLinkedList(); 
        // Copy Constructor
        SinglyLinkedList(const SinglyLinkedList<T> & other);
        // Move Constructor
        SinglyLinkedList(SinglyLinkedList<T> && other);
        //Getter for head
        Node<T>* get_head() const;
        // Insert at beginning
        void insert_at_head(const T& value);
        // Insert at End
        void insert_at_end(const T& value);
        // Insert at index
        void insert_at_index(int index, const T& value);
        // Deletion at beginning
        void delete_at_head();
        // Deletion at End
        void delete_at_end();
        // delete at index
        void delete_at_index(int index);
        // Search by value
        std::shared_ptr<Node<T>> search_by_value(const T& value) const;
        // Get the size 
        int get_size() const;
        // Display the list
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& list);

         
};


template <typename T>  class Stack{
    private:
        SinglyLinkedList<T> stack_list;
    public:
        // Constructor
        Stack();
        // Copy Constructor
        Stack(const Stack<T> & other);
        // Move Constructor
        Stack( Stack<T> && other);
        // Push
        void push(const T&value);
        // Pop
        T pop();
        // Peek
        T peek();
        // isEmpty
        bool isEmpty();
        // Display the stack
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Stack<U>& list);

         
};


#endif