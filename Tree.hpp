//danielcohen1717@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include "HeapIterator.hpp"

using namespace std;

template <typename T, int K = 2>
class Tree {
public:
    Tree();  // Constructor
    ~Tree();  // Destructor

    void add_root(const Node<T>& node);  // Add root node
    void add_sub_node(const Node<T>& parent, const Node<T>& child);  // Add child node
    Node<T>* find_node(Node<T>* node, T value);  // Find node by value

    // Iterator methods
    PreOrderIterator<T, K> begin_pre_order();
    PreOrderIterator<T, K> end_pre_order();
    PostOrderIterator<T, K> begin_post_order();
    PostOrderIterator<T, K> end_post_order();
    InOrderIterator<T, K> begin_in_order();
    InOrderIterator<T, K> end_in_order();
    BFSIterator<T> begin_bfs_scan();
    BFSIterator<T> end_bfs_scan();
    DFSIterator<T> begin_dfs_scan();
    DFSIterator<T> end_dfs_scan();
    HeapIterator<T> begin_heap();
    HeapIterator<T> end_heap();

    void myHeap();  // Convert to heap
    void heapify_node(Node<T>* node);  // Heapify node

    void displayGui() const;  // Display GUI

private:
    Node<T>* root;  // Root node
    void drawTree(sf::RenderWindow& window, sf::Font& font, Node<T>* node, float x, float y, float spaceBetweenNodes) const;  // Draw tree

    template <typename U, int L>
    friend std::ostream& operator<<(std::ostream& os, const Tree<U, L>& tree);
};

#include "Tree.tpp"
#endif // TREE_HPP
