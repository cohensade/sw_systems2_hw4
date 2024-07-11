//danielcohen1717@gmail.com

#ifndef PRE_ORDER_ITERATOR_TPP
#define PRE_ORDER_ITERATOR_TPP

template <typename T>
PreOrderIterator<T>::PreOrderIterator(Node<T>* root) {
    if (root != nullptr) stack.push(root); // Push the root node to the stack
}

template <typename T>
bool PreOrderIterator<T>::operator!=(const PreOrderIterator& other) const {
    // The iterators are not equal if the stack is not empty
    return !stack.empty();
}

template <typename T>
PreOrderIterator<T>& PreOrderIterator<T>::operator++() {
    Node<T>* node = stack.top(); // Get the node at the top of the stack
    stack.pop(); // Remove the node from the stack
    // Push all children of the node to the stack in reverse order
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        stack.push(*it);
    }
    return *this;
}

template <typename T>
Node<T>& PreOrderIterator<T>::operator*() const {
    // Return a reference to the node at the top of the stack
    return *stack.top();
}

#endif // PRE_ORDER_ITERATOR_TPP
