//danielcohen1717@gmail.com

#ifndef PRE_ORDER_ITERATOR_HPP
#define PRE_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

// PreOrderIterator class template for iterating through a tree in pre-order
template <typename T>
class PreOrderIterator {
private:
    std::stack<Node<T>*> stack; // Stack for traversing the tree
public:
    // Constructor initializes the stack with the root node
    PreOrderIterator(Node<T>* root);

    // Operator to compare iterators (checks if the stack is empty)
    bool operator!=(const PreOrderIterator& other) const;

    // Prefix increment operator to move to the next node
    PreOrderIterator& operator++();

    // Dereference operator to access the current node
    Node<T>& operator*() const;
};

#include "PreOrderIterator.tpp"
#endif // PRE_ORDER_ITERATOR_HPP
