#ifndef POST_ORDER_ITERATOR_TPP
#define POST_ORDER_ITERATOR_TPP

template <typename T, int K>
void PostOrderIterator<T, K>::post_order_traversal(Node<T>* root) {
    if (root != nullptr) {
        stack.push(root); // Push the root node to the stack
        while (!stack.empty()) {
            Node<T>* node = stack.top();
            stack.pop();
            output.push(node); // Push the node to the output stack
            // Push children in reverse order to process right subtree first
            for (auto it = node->children.begin(); it != node->children.end(); ++it) {
                stack.push(*it);
            }
        }
    }
}

template <typename T, int K>
void PostOrderIterator<T, K>::dfs_traversal(Node<T>* root) {
    if (root != nullptr) {
        std::stack<Node<T>*> tempStack; // Temporary stack to hold nodes in correct order
        tempStack.push(root); // Push the root node to the temporary stack
        while (!tempStack.empty()) {
            Node<T>* node = tempStack.top();
            tempStack.pop();
            stack.push(node); // Push the node to the main stack
            // Push children in reverse order to process them from left to right
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                tempStack.push(*it);
            }
        }
        // Transfer nodes from stack to output in correct order
        while (!stack.empty()) {
            Node<T>* node = stack.top();
            stack.pop();
            output.push(node);
        }
    }
}

template <typename T, int K>
PostOrderIterator<T, K>::PostOrderIterator(Node<T>* root) {
    if (K == 2) {
        post_order_traversal(root); // Use post-order traversal for binary trees
    } else {
        dfs_traversal(root); // Use DFS traversal for k-ary trees
    }
}

template <typename T, int K>
bool PostOrderIterator<T, K>::operator!=(const PostOrderIterator& other) const {
    // The iterators are not equal if the output stack is not empty
    return !output.empty();
}

template <typename T, int K>
PostOrderIterator<T, K>& PostOrderIterator<T, K>::operator++() {
    // Pop the top node from the output stack
    output.pop();
    return *this;
}

template <typename T, int K>
Node<T>& PostOrderIterator<T, K>::operator*() const {
    // Return a reference to the node at the top of the output stack
    return *output.top();
}

#endif // POST_ORDER_ITERATOR_TPP
