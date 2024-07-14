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

// Helper function to print Complex values
void printComplexVector(const std::vector<Complex>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
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

    if (expected != result) {
        std::cout << "PreOrderTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
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

    if (expected != result) {
        std::cout << "PostOrderTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
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

    if (expected != result) {
        std::cout << "InOrderTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
    }

    CHECK(expected == result);
}

TEST_CASE("ThreeAryTreePostOrderTraversal") {
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

    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        result.push_back((*node).get_value());
    }

    if (expected != result) {
        std::cout << "ThreeAryTreePostOrderTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
    }

    CHECK(expected == result);
}


TEST_CASE("ThreeAryTreeHeapTraversal") {
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

    CHECK_THROWS_WITH(
        for (auto node = three_ary_tree.begin_heap(); node != three_ary_tree.end_heap(); ++node) {
            // This loop should throw an exception, so the body can be empty.
        },
        "Heap traversal is only valid for binary trees."
    );
}



TEST_CASE("ThreeAryTreeInOrderTraversal") {
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

    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        result.push_back((*node).get_value());
    }

    if (expected != result) {
        std::cout << "ThreeAryTreeInOrderTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
    }

    CHECK(expected == result);
}


TEST_CASE("EmptyTreeTraversal") {
    Tree<Complex> tree;

    std::vector<Complex> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(result.empty());

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(result.empty());

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(result.empty());
}

TEST_CASE("SingleNodeTreeTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2));
    tree.add_root(root_node);

    std::vector<Complex> expected = {Complex(1.1, 2.2)};
    std::vector<Complex> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(expected == result);

    result.clear();
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(expected == result);

    result.clear();
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result.push_back((*node).get_value());
    }
    CHECK(expected == result);
}

TEST_CASE("BreadthFirstTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(11.11, 12.12)};
    std::vector<Complex> result;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result.push_back((*node).get_value());
    }

    if (expected != result) {
        std::cout << "BreadthFirstTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
    }

    CHECK(expected == result);
}

TEST_CASE("DepthFirstTraversal") {
    Tree<Complex> tree;
    Node<Complex> root_node(Complex(1.1, 2.2)), n1(Complex(3.3, 4.4)), n2(Complex(5.5, 6.6)), n3(Complex(7.7, 8.8)), n4(Complex(9.9, 10.1)), n5(Complex(11.11, 12.12));
    setupTree(tree, root_node, n1, n2, n3, n4, n5);

    std::vector<Complex> expected = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(7.7, 8.8), Complex(9.9, 10.1), Complex(5.5, 6.6), Complex(11.11, 12.12)};
    std::vector<Complex> result;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        result.push_back((*node).get_value());
    }

    if (expected != result) {
        std::cout << "DepthFirstTraversal failed!" << std::endl;
        std::cout << "Expected: ";
        printComplexVector(expected);
        std::cout << "Actual: ";
        printComplexVector(result);
    }

    CHECK(expected == result);
}
