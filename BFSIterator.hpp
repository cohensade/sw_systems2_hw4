//danielcohen1717@gmail.com

#ifndef BFS_ITERATOR_HPP
#define BFS_ITERATOR_HPP

#include <queue>
#include "Node.hpp"

template <typename T>
class BFSIterator {
private:
    std::queue<Node<T>*> queue;  // Queue to store nodes for BFS traversal
public:
    BFSIterator(Node<T>* root);  // Constructor initializes queue with root

    bool operator!=(const BFSIterator& other) const;  // Compare if iterators are not equal
    BFSIterator& operator++();  // Move to the next node
    Node<T>& operator*() const;  // Dereference to get the current node
};

#include "BFSIterator.tpp"
#endif // BFS_ITERATOR_HPP
