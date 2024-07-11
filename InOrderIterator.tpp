//danielcohen1717@gmail.com

#ifndef IN_ORDER_ITERATOR_TPP
#define IN_ORDER_ITERATOR_TPP

template <typename T>
InOrderIterator<T>::InOrderIterator(Node<T>* root) : current(root) {
    // Initialize the stack with the leftmost nodes
    while (current != nullptr) {
        stack.push(current);
        current = current->children.size() > 0 ? current->children[0] : nullptr;
    }
}

template <typename T>
bool InOrderIterator<T>::operator!=(const InOrderIterator& other) const {
    return !stack.empty();  // Check if there are still nodes to visit
}

template <typename T>
InOrderIterator<T>& InOrderIterator<T>::operator++() {
    // Move to the next node in the in-order traversal
    Node<T>* node = stack.top();
    stack.pop();
    if (node->children.size() > 1) {
        current = node->children[1];
        while (current != nullptr) {
            stack.push(current);
            current = current->children.size() > 0 ? current->children[0] : nullptr;
        }
    }
    return *this;
}

template <typename T>
Node<T>& InOrderIterator<T>::operator*() const {
    return *stack.top();  // Return the current node
}

#endif // IN_ORDER_ITERATOR_TPP
