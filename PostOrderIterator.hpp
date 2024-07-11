//danielcohen1717@gmail.com

#ifndef POST_ORDER_ITERATOR_HPP
#define POST_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

// PostOrderIterator class template for iterating through a tree in post-order
template <typename T>
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack; // Stack for traversing the tree
    std::stack<Node<T>*> output; // Stack for storing nodes in post-order
public:
    // Constructor initializes the stacks and pushes nodes in post-order
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
