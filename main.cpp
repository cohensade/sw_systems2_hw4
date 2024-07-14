//danielcohen1717@gmail.com

#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;

int main() {
    // Create the root node with a Complex number
    Node<Complex> root_node(Complex(1.1, 2.2));
    
    // Create a tree and add the root node
    Tree<Complex> tree;
    tree.add_root(root_node);
    
    // Create additional nodes with Complex numbers
    Node<Complex> n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));

    // Add the nodes to the tree
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Print the tree using pre-order traversal
    cout << "Pre order iterator: " << endl;
    try {
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            cout << (*node).get_value() << endl;
        }
    } catch (const std::logic_error& e) {
        cout << e.what() << endl;
    }

    // Print the tree using post-order traversal
    cout << "Post order iterator: " << endl;
    try {
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            cout << (*node).get_value() << endl;
        }
    } catch (const std::logic_error& e) {
        cout << e.what() << endl;
    }

    // Print the tree using in-order traversal
    cout << "In order iterator: " << endl;
    try {
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            cout << (*node).get_value() << endl;
        }
    } catch (const std::logic_error& e) {
        cout << e.what() << endl;
    }

    // Print the tree using BFS traversal
    cout << "BFS iterator: " << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node).get_value() << endl;
    }

    // Print the tree using DFS traversal
    cout << "DFS iterator: " << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << (*node).get_value() << endl;
    }

    // Convert the tree to a heap
    tree.myHeap();

    // Print the tree using heap traversal
    cout << "Heap iterator: " << endl;
    try {
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
            cout << (*node)->get_value() << endl;
        }
    } catch (const std::logic_error& e) {
        cout << e.what() << endl;
    }

    // Create a 3-ary tree and add nodes
    Tree<Complex, 3> three_ary_tree;
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    // Print the 3-ary tree using DFS traversal
    cout << "3-ary tree DFS iterator: " << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        cout << (*node).get_value() << endl;
    }

    cout << "3-ary tree Post order iterator: " << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        cout << (*node).get_value() << endl;
    }

    cout << "3-ary tree Pre order iterator: " << endl;
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node) {
        cout << (*node).get_value() << endl;
    }

    cout << "3-ary tree In order iterator: " << endl;
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        cout << (*node).get_value() << endl;
    }

    //display the tree
    // three_ary_tree.displayGui();
    // tree.displayGui();

    return 0;
}

//binary tree
// The tree should look like:
    /**
     *    root = 1.1 + 2i
     *     /            \
     *    3 +4i         5 +6i
     *   /  \          /     \
     *  7+8i  9+10i   11+12i
     */


//none binary tree
// The tree should look like:
    /**
     *       root = 1.1 + 2i
     *     /       \          \
     *    3 +4i     5 +6i      7+8i
     *   /  \      /  \
     *  9+10i  11+12i  
     */
