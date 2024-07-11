//danielcohen1717@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node {
public:
    T value;  // Value of the node
    std::vector<Node<T>*> children;  // Vector of child nodes

    Node(T val);  // Constructor
    ~Node();  // Destructor
    T get_value() const;  // Getter for node value
};

#include "Node.tpp"
#endif // NODE_HPP
