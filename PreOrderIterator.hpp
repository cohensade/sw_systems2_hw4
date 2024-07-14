#ifndef PRE_ORDER_ITERATOR_HPP
#define PRE_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

// PreOrderIterator class template for iterating through a tree in pre-order or DFS order
template <typename T, int K = 2>
class PreOrderIterator {
private:
    std::stack<Node<T>*> stack; // Stack for traversing the tree
    std::stack<Node<T>*> output; // Stack for storing nodes in pre-order or DFS order

    // Helper function to perform pre-order traversal for binary trees
    void pre_order_traversal(Node<T>* root);

    // Helper function to perform DFS traversal for non-binary trees
    void dfs_traversal(Node<T>* root);

public:
    // Constructor initializes the stack and pushes nodes in pre-order or DFS order
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
