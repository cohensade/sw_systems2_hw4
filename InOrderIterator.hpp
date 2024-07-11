//danielcohen1717@gmail.com

#ifndef IN_ORDER_ITERATOR_HPP
#define IN_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

template <typename T>
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;  // Stack to hold nodes for in-order traversal
    Node<T>* current;  // Pointer to the current node

public:
    InOrderIterator(Node<T>* root);  // Constructor to initialize the iterator with the root node

    bool operator!=(const InOrderIterator& other) const;  // Inequality operator to compare iterators
    InOrderIterator& operator++();  // Pre-increment operator to move to the next node in the traversal
    Node<T>& operator*() const;  // Dereference operator to access the current node
};

#include "InOrderIterator.tpp"
#endif // IN_ORDER_ITERATOR_HPP
