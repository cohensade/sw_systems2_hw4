# Trees - STL, Templates, and Iterators

## Author
My name is Daniel Cohen Sade.  
Email: danielcohen1717@gmail.com

## Overview
This project is a C++ implementation of Tree class and iterators over the tree. The project include Node class to represent each node of the tree, Tree class that we will make k-ary trees and we have some iterators that will iterate over the trees.


## Hierarchy of Classes

This project implements a k-ary tree container with various iterators for traversing the tree. The primary classes and their relationships are as follows:

### 1. `Node`
- **Description**: Represents a single node in the tree.
- **Attributes**:
  - `value`: The value stored in the node.
  - `children`: A vector of pointers to child nodes.
- **Methods**:
  - Constructor: Initializes the node with a value.
  - Destructor: Recursively deletes child nodes.
  - `get_value`: Returns the value of the node.

### 2. `Tree`
- **Description**: Represents the tree data structure.
- **Template Parameters**:
  - `T`: Type of values stored in the nodes.
  - `K`: The maximum number of children each node can have (default is 2, for a binary tree).
- **Attributes**:
  - `root`: Pointer to the root node of the tree.
- **Methods**:
  - Constructor: Initializes an empty tree.
  - Destructor: Deletes the root node, which recursively deletes all nodes.
  - `add_root`: Adds a root node to the tree.
  - `add_sub_node`: Adds a child node to a specified parent node.
  - `find_node`: Finds a node with a given value.
  - Iterators: Provides various iterators for tree traversal (pre-order, post-order, in-order, BFS, DFS, heap).
  - `myHeap`: Converts the tree into a min-heap.
  - `displayGui`: Displays the tree using a graphical user interface (GUI) with SFML.

### 3. `Complex`
- **Description**: Represents a complex number with real and imaginary parts.
- **Attributes**:
  - `real`: The real part of the complex number.
  - `imag`: The imaginary part of the complex number.
- **Methods**:
  - Arithmetic operators (`+`, `-`, `*`, `/`): Perform arithmetic operations with other complex numbers.
  - Comparison operators (`==`, `>`, `<`): Compare complex numbers.
  - Stream operators (`<<`, `>>`): Output and input complex numbers.
  - `to_string`: Returns a string representation of the complex number.

### Iterators
- **Description**: Iterators are used to traverse the tree in different orders.
- **Common Attributes**:
  - `stack` or `queue`: Data structures used to manage the traversal state.
- **Common Methods**:
  - Constructor: Initializes the iterator with the root node.
  - `operator!=`: Checks if the iterator has reached the end.
  - `operator++`: Advances the iterator to the next node.
  - `operator*`: Accesses the current node.
- **Types of Iterators**:
  - `PreOrderIterator`: Pre-order traversal (node, left, right).
  - `PostOrderIterator`: Post-order traversal (left, right, node).
  - `InOrderIterator`: In-order traversal (left, node, right).
  - `BFSIterator`: Breadth-first search traversal.
  - `DFSIterator`: Depth-first search traversal.
  - `HeapIterator`: Traversal in heap order.

## Libraries Used

1. **Standard Template Library (STL)**
   - Containers: `vector`, `stack`, `queue`
   - Algorithms: `std::swap`

2. **SFML (Simple and Fast Multimedia Library)**
   - **Purpose**: Used for creating the graphical user interface (GUI) to display the tree.
   - **Components**:
     - `sf::RenderWindow`: For creating a window.
     - `sf::Font`: For loading and setting fonts.
     - `sf::Text`: For displaying text.
     - `sf::CircleShape`: For drawing circles (representing nodes).
     - `sf::Event`: For handling window events.

3. **Input/Output Stream Library**
   - Used for overloading stream operators in the `Complex` class.

## How to Compile and Run

1. **Requirements**:
   - SFML library installed on your system.
   - A C++ compiler supporting C++11 or higher.

2. **Compilation**:
   ```sh
   to compile the files:
   make 
  
  to run the main:
   make tree 
   
3. **Tests**:
   ```sh
    ./test	   
   

