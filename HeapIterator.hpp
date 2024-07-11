//danielcohen1717@gmail.com

#ifndef HEAP_ITERATOR_HPP
#define HEAP_ITERATOR_HPP

#include <vector>
#include "Node.hpp"

template <typename T>
class HeapIterator {
public:
    HeapIterator(Node<T>* root);  // Constructor to initialize the heap iterator with root node
    HeapIterator& operator++();  // Pre-increment operator to move to the next node in the heap
    Node<T>* operator*();  // Dereference operator to access the current node
    bool operator!=(const HeapIterator& other) const;  // Inequality operator to compare iterators

    void setEndIterator(size_t index);  // Set the end iterator index
    const std::vector<Node<T>*>& getHeap() const;  // Get the vector representing the heap

private:
    std::vector<Node<T>*> heap;  // Vector to store nodes in heap order
    size_t index;  // Current index in the heap

    void heapify();  // Function to convert the tree into a heap
    void heapify_down(size_t idx);  // Function to maintain the heap property
};

#include "HeapIterator.tpp"
#endif // HEAP_ITERATOR_HPP
