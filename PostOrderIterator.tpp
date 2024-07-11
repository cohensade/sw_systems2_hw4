//danielcohen1717@gmail.com

#ifndef POST_ORDER_ITERATOR_TPP
#define POST_ORDER_ITERATOR_TPP

template <typename T>
PostOrderIterator<T>::PostOrderIterator(Node<T>* root) {
    if (root != nullptr) {
        stack.push(root); // Push the root node to the stack
        while (!stack.empty()) {
            Node<T>* node = stack.top();
            stack.pop();
            output.push(node); // Push the node to the output stack
            // Push all children of the node to the stack
            for (auto child : node->children) {
                stack.push(child);
            }
        }
    }
}

template <typename T>
bool PostOrderIterator<T>::operator!=(const PostOrderIterator& other) const {
    // The iterators are not equal if the output stack is not empty
    return !output.empty();
}

template <typename T>
PostOrderIterator<T>& PostOrderIterator<T>::operator++() {
    // Pop the top node from the output stack
    output.pop();
    return *this;
}

template <typename T>
Node<T>& PostOrderIterator<T>::operator*() const {
    // Return a reference to the node at the top of the output stack
    return *output.top();
}

#endif // POST_ORDER_ITERATOR_TPP
