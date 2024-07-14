#ifndef IN_ORDER_ITERATOR_TPP
#define IN_ORDER_ITERATOR_TPP

template <typename T, int K>
void InOrderIterator<T, K>::in_order_traversal(Node<T>* root) {
    current = root; //starting point to traversal
    //if there is a next node the while go on
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            //go to the most left path of the tree
            stack.push(current);
            current = current->children.empty() ? nullptr : current->children[0];
        }
        current = stack.top();
        stack.pop();
        return;
    }
}

template <typename T, int K>
void InOrderIterator<T, K>::dfs_traversal(Node<T>* root) {
    if (root != nullptr) {
        std::stack<std::pair<Node<T>*, int>> tempStack; // Stack to hold nodes and child indices
        tempStack.push({root, 0}); // Push the root node with child index 0

        while (!tempStack.empty()) {
            auto [node, index] = tempStack.top();
            tempStack.pop();

            if (index == 0) {
                // Visit the node before its children
                stack.push(node);
            }

            if (index < node->children.size()) {
                // Push the node back with the next child index
                tempStack.push({node, index + 1});
                // Push the current child in normal order (left to right)
                tempStack.push({node->children[index], 0});
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
InOrderIterator<T, K>::InOrderIterator(Node<T>* root) : current(nullptr) {
    if (K == 2) {
        in_order_traversal(root); // Use in-order traversal for binary trees
    } else {
        dfs_traversal(root); // Use DFS traversal for k-ary trees
    }
}

template <typename T, int K>
bool InOrderIterator<T, K>::operator!=(const InOrderIterator& other) const {
    return !(output.empty() && current == nullptr);
}

template <typename T, int K>
InOrderIterator<T, K>& InOrderIterator<T, K>::operator++() {
    if (K == 2) {
        current = current->children.size() > 1 ? current->children[1] : nullptr;
        while (current != nullptr) {
            stack.push(current);
            current = current->children.empty() ? nullptr : current->children[0];
        }
        if (!stack.empty()) {
            current = stack.top();
            stack.pop();
        } else {
            current = nullptr;
        }
    } else {
        if (!output.empty()) {
            output.pop();
        }
    }
    return *this;
}

template <typename T, int K>
Node<T>& InOrderIterator<T, K>::operator*() const {
    if (K == 2) {
        return *current;
    } else {
        return *output.top();
    }
}

#endif // IN_ORDER_ITERATOR_TPP
