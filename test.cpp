#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Complex.hpp"
#include "Tree.hpp"

// Helper function to set up the tree
void setupTree(Tree<Complex>& tree, Node<Complex>& root_node, Node<Complex>& n1, Node<Complex>& n2, Node<Complex>& n3, Node<Complex>& n4, Node<Complex>& n5) {
    root_node = Node<Complex>(Complex(1.1, 2.2));
    n1 = Node<Complex>(Complex(3.3, 4.4));
    n2 = Node<Complex>(Complex(5.5, 6.6));
    n3 = Node<Complex>(Complex(7.7, 8.8));
    n4 = Node<Complex>(Complex(9.9, 10.1));
    n5 = Node<Complex>(Complex(11.11, 12.12));

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
}

TEST_CASE("PreOrderTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(5.5, 6.6), Complex(11.11, 12.12)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("PostOrderTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(3.3, 4.4), Complex(11.11, 12.12), Complex(5.5, 6.6), Complex(1.1, 2.2)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("InOrderTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(7.7, 8.8), Complex(3.3, 4.4), Complex(9.9, 10.1), Complex(1.1, 2.2), Complex(11.11, 12.12), Complex(5.5, 6.6)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("BFSTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(11.11, 12.12)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("DFSTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(5.5, 6.6), Complex(11.11, 12.12)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("HeapTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    tree.myHeap();
    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(11.11, 12.12)};
    std::vector<Complex> result;
    
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        result.push_back((*node)->get_value());
    }

    CHECK(expected == result);
}

TEST_CASE("ThreeAryTreeDFSTraversal") {
    Tree<Complex, 3> three_ary_tree;
    Node<Complex> root_node(Complex(1.1, 2.2));
    Node<Complex> n1(Complex(3.3, 4.4));
    Node<Complex> n2(Complex(5.5, 6.6));
    Node<Complex> n3(Complex(7.7, 8.8));
    Node<Complex> n4(Complex(9.9, 10.1));
    Node<Complex> n5(Complex(11.11, 12.12));
    
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(9.9, 10.1), Complex(5.5, 6.6), Complex(11.11, 12.12), Complex(7.7, 8.8)};
    std::vector<Complex> result;

    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        result.push_back((*node).get_value());
    }

    CHECK(expected == result);
}
