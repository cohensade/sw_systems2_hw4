//danielcohen1717@gmail.com

#ifndef BFS_ITERATOR_TPP
#define BFS_ITERATOR_TPP

template <typename T>
BFSIterator<T>::BFSIterator(Node<T>* root) {
    if (root != nullptr) queue.push(root);  // Initialize queue with root if not null
}

template <typename T>
bool BFSIterator<T>::operator!=(const BFSIterator& other) const {
    return !queue.empty();  //checks if the current iterator is still valid
}

template <typename T>
BFSIterator<T>& BFSIterator<T>::operator++() {
    Node<T>* node = queue.front();  // Get the front node from the queue
    queue.pop();  // Remove the front node from the queue
    for (auto child : node->children) {  // Add all children of the current node to the queue
        queue.push(child);
    }
    return *this;  // Return the iterator itself
}

template <typename T>
Node<T>& BFSIterator<T>::operator*() const {
    return *queue.front();  // Dereference to get the front node in the queue
    //accsess to the object
}

#endif // BFS_ITERATOR_TPP
