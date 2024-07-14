#ifndef IN_ORDER_ITERATOR_HPP
#define IN_ORDER_ITERATOR_HPP

#include <stack>
#include "Node.hpp"

template <typename T, int K = 2>
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;
    std::stack<Node<T>*> output;
    Node<T>* current;

    void in_order_traversal(Node<T>* root);
    void dfs_traversal(Node<T>* root);

public:
    InOrderIterator(Node<T>* root);

    bool operator!=(const InOrderIterator& other) const;
    InOrderIterator& operator++();
    Node<T>& operator*() const;
};

#include "InOrderIterator.tpp" 

#endif // IN_ORDER_ITERATOR_HPP
