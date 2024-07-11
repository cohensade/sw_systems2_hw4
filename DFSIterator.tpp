//danielcohen1717@gmail.com

#ifndef DFS_ITERATOR_TPP
#define DFS_ITERATOR_TPP

template <typename T>
DFSIterator<T>::DFSIterator(Node<T>* root) {
    if (root != nullptr) stack.push(root);  // Initialize stack with root node if not null
}

template <typename T>
bool DFSIterator<T>::operator!=(const DFSIterator& other) const {
    return !stack.empty();  // Check if stack is not empty
}

template <typename T>
DFSIterator<T>& DFSIterator<T>::operator++() {
    Node<T>* node = stack.top();  // Get the current node from the stack
    stack.pop();  // Remove the current node from the stack
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(*it);  // Add all children of the current node to the stack in reverse order
    }
    return *this;  // Return the iterator
}

template <typename T>
Node<T>& DFSIterator<T>::operator*() const {
    return *stack.top();  // Return the current node at the top of the stack
}

#endif // DFS_ITERATOR_TPP
