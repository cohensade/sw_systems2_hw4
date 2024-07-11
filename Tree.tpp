//danielcohen1717@gmail.com

#ifndef TREE_TPP
#define TREE_TPP

#include <queue>
#include <vector>
#include <SFML/Graphics.hpp>

template <typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}  // Constructor initializes root to nullptr

template <typename T, int K>
Tree<T, K>::~Tree() {
    delete root;  // Destructor deletes root
}

template <typename T, int K>
void Tree<T, K>::add_root(const Node<T>& node) {
    if (root != nullptr) delete root;  // Delete existing root
    root = new Node<T>(node.value);  // Set new root
}

template <typename T, int K>
void Tree<T, K>::add_sub_node(const Node<T>& parent, const Node<T>& child) {
    Node<T>* parentNode = find_node(root, parent.value);
    if (parentNode && parentNode->children.size() < K) {
        parentNode->children.push_back(new Node<T>(child.value));  // Add child node
    }
}

template <typename T, int K>
Node<T>* Tree<T, K>::find_node(Node<T>* node, T value) {
    if (node == nullptr) return nullptr;
    if (node->value == value) return node;
    for (auto child : node->children) {
        Node<T>* found = find_node(child, value);
        if (found) return found;
    }
    return nullptr;
}

// Iterator methods
template <typename T, int K>
PreOrderIterator<T> Tree<T, K>::begin_pre_order() {
    if (K != 2) throw std::logic_error("Pre-order traversal is only valid for binary trees.");
    return PreOrderIterator<T>(root);
}

template <typename T, int K>
PreOrderIterator<T> Tree<T, K>::end_pre_order() {
    if (K != 2) throw std::logic_error("Pre-order traversal is only valid for binary trees.");
    return PreOrderIterator<T>(nullptr);
}

template <typename T, int K>
PostOrderIterator<T> Tree<T, K>::begin_post_order() {
    if (K != 2) throw std::logic_error("Post-order traversal is only valid for binary trees.");
    return PostOrderIterator<T>(root);
}

template <typename T, int K>
PostOrderIterator<T> Tree<T, K>::end_post_order() {
    if (K != 2) throw std::logic_error("Post-order traversal is only valid for binary trees.");
    return PostOrderIterator<T>(nullptr);
}

template <typename T, int K>
InOrderIterator<T> Tree<T, K>::begin_in_order() {
    if (K != 2) throw std::logic_error("In-order traversal is only valid for binary trees.");
    return InOrderIterator<T>(root);
}

template <typename T, int K>
InOrderIterator<T> Tree<T, K>::end_in_order() {
    if (K != 2) throw std::logic_error("In-order traversal is only valid for binary trees.");
    return InOrderIterator<T>(nullptr);
}

template <typename T, int K>
BFSIterator<T> Tree<T, K>::begin_bfs_scan() {
    return BFSIterator<T>(root);
}

template <typename T, int K>
BFSIterator<T> Tree<T, K>::end_bfs_scan() {
    return BFSIterator<T>(nullptr);
}

template <typename T, int K>
DFSIterator<T> Tree<T, K>::begin_dfs_scan() {
    return DFSIterator<T>(root);
}

template <typename T, int K>
DFSIterator<T> Tree<T, K>::end_dfs_scan() {
    return DFSIterator<T>(nullptr);
}

template <typename T, int K>
HeapIterator<T> Tree<T, K>::begin_heap() {
    if (K != 2) throw std::logic_error("Heap traversal is only valid for binary trees.");
    return HeapIterator<T>(root);
}

template <typename T, int K>
HeapIterator<T> Tree<T, K>::end_heap() {
    HeapIterator<T> endIter(root);
    endIter.setEndIterator(endIter.getHeap().size()); // Ensure end iterator has index set to heap size
    return endIter;
}

template <typename T, int K>
void Tree<T, K>::myHeap() {
    if (K != 2) throw std::logic_error("Heap conversion is only valid for binary trees.");
    
    // Convert tree to array representation
    std::vector<Node<T>*> nodes;
    if (root != nullptr) {
        std::queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* node = q.front();
            q.pop();
            nodes.push_back(node);
            for (auto child : node->children) {
                q.push(child);
            }
        }
    }

    // Perform heapify in bottom-up manner
    for (int i = nodes.size() / 2 - 1; i >= 0; --i) {
        heapify_node(nodes[i]);
    }
}

template <typename T, int K>
void Tree<T, K>::heapify_node(Node<T>* node) {
    if (node == nullptr) return;

    for (auto child : node->children) {
        if (child->value < node->value) {
            std::swap(node->value, child->value);
        }
        heapify_node(child);
    }
}

// GUI display method
template <typename T, int K>
void Tree<T, K>::displayGui() const {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree GUI");
    sf::Font font;
    if (!font.loadFromFile("myfont.otf")) {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    window.clear(sf::Color::White);
    float spaceOfNodes = 600 / K;
    drawTree(window, font, root, 350, 20, spaceOfNodes);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.clear(sf::Color::White);
                window.close();
            }
        }
    }
}

// Helper function to draw the tree
template <typename T, int K>
void Tree<T, K>::drawTree(sf::RenderWindow& window, sf::Font& font, Node<T>* node, float x, float y, float spaceBetweenNodes) const {
    if (!node) return;

    sf::CircleShape circle(35);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Yellow);
    window.draw(circle);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setString(node->value.to_string());
    text.setPosition(x + circle.getRadius() / 2, y + circle.getRadius() / 2);
    window.draw(text);

    size_t childrens = node->children.size();
    if (childrens > 0) {
        for (size_t i = 0; i < childrens; i++) {
            float xOfChild = (x - spaceBetweenNodes / 2) + (i * spaceBetweenNodes);
            float yOfChild = y + 100;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + circle.getRadius(), y + circle.getRadius() * 2)),
                sf::Vertex(sf::Vector2f(xOfChild + circle.getRadius(), yOfChild))
            };
            line[0].color = sf::Color::Black;
            line[1].color = sf::Color::Black;
            window.draw(line, 2, sf::Lines);
            drawTree(window, font, node->children[i], xOfChild, yOfChild, spaceBetweenNodes / 2);
        }
    }
}

template <typename T, int K>
std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree) {
    tree.displayGui();
    return os;
}

#endif // TREE_TPP
