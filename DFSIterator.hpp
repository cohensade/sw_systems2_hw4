//danielcohen1717@gmail.com

#ifndef DFS_ITERATOR_HPP
#define DFS_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

template <typename T>
class DFSIterator {
private:
    std::stack<Node<T>*> stack;  // Stack to store nodes for DFS traversal
public:
    DFSIterator(Node<T>* root);  // Constructor to initialize the stack with root node

    bool operator!=(const DFSIterator& other) const;  // Inequality operator to check if stack is empty
    DFSIterator& operator++();  // Pre-increment operator to move to the next node in DFS
    Node<T>& operator*() const;  // Dereference operator to access the current node
};

#include "DFSIterator.tpp"
#endif // DFS_ITERATOR_HPP
