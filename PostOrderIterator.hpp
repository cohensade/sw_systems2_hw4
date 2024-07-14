#ifndef POST_ORDER_ITERATOR_HPP
#define POST_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

// PostOrderIterator class template for iterating through a tree in post-order or DFS order
template <typename T, int K = 2>
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack; // Stack for traversing the tree
    std::stack<Node<T>*> output; // Stack for storing nodes in post-order or DFS order

    // Helper function to perform post-order traversal for binary trees
    void post_order_traversal(Node<T>* root);

    // Helper function to perform DFS traversal for non-binary trees
    void dfs_traversal(Node<T>* root);

public:
    // Constructor initializes the stacks and pushes nodes in post-order or DFS order
    PostOrderIterator(Node<T>* root);

    // Operator to compare iterators (checks if the output stack is empty)
    bool operator!=(const PostOrderIterator& other) const;

    // Prefix increment operator to move to the next node
    PostOrderIterator& operator++();

    // Dereference operator to access the current node
    Node<T>& operator*() const;
};

#include "PostOrderIterator.tpp"
#endif // POST_ORDER_ITERATOR_HPP
