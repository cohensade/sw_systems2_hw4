#ifndef PRE_ORDER_ITERATOR_TPP
#define PRE_ORDER_ITERATOR_TPP

template <typename T, int K>
void PreOrderIterator<T, K>::pre_order_traversal(Node<T>* root) {
    if (root != nullptr) {
        stack.push(root);
    }
}

template <typename T, int K>
void PreOrderIterator<T, K>::dfs_traversal(Node<T>* root) {
    if (root != nullptr) {
        stack.push(root);
    }
}

template <typename T, int K>
PreOrderIterator<T, K>::PreOrderIterator(Node<T>* root) {
    if (K == 2) {
        pre_order_traversal(root); // Use pre-order traversal for binary trees
    } else {
        dfs_traversal(root); // Use DFS traversal for k-ary trees
    }
}

template <typename T, int K>
bool PreOrderIterator<T, K>::operator!=(const PreOrderIterator& other) const {
    return !stack.empty();
}

template <typename T, int K>
PreOrderIterator<T, K>& PreOrderIterator<T, K>::operator++() {
    if (!stack.empty()) {
        Node<T>* node = stack.top();
        stack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            stack.push(*it);
        }
    }
    return *this;
}

template <typename T, int K>
Node<T>& PreOrderIterator<T, K>::operator*() const {
    return *stack.top();
}

#endif // PRE_ORDER_ITERATOR_TPP
