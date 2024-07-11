//danielcohen1717@gmail.com

#ifndef NODE_TPP
#define NODE_TPP

template <typename T>
Node<T>::Node(T val) : value(val) {}  // Initialize node with a value

template <typename T>
Node<T>::~Node() {
    // Delete all child nodes to avoid memory leaks
    for (auto child : children) {
        delete child;
    }
}

template <typename T>
T Node<T>::get_value() const {
    return value;  // Return the value of the node
}

#endif // NODE_TPP
