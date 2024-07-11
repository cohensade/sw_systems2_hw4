//danielcohen1717@gmail.com

#ifndef HEAP_ITERATOR_TPP
#define HEAP_ITERATOR_TPP

#include "HeapIterator.hpp"
#include <algorithm>

template <typename T>
HeapIterator<T>::HeapIterator(Node<T>* root) : index(0) {
    if (root) {
        heap.push_back(root);  // Add root node to the heap
        for (size_t i = 0; i < heap.size(); ++i) {
            for (auto child : heap[i]->children) {
                heap.push_back(child);  // Add children nodes to the heap
            }
        }
        heapify();  // Convert the tree to a heap
    }
}

template <typename T>
HeapIterator<T>& HeapIterator<T>::operator++() {
    ++index;  // Move to the next node in the heap
    return *this;
}

template <typename T>
Node<T>* HeapIterator<T>::operator*() {
    return heap[index];  // Return the current node in the heap
}

template <typename T>
bool HeapIterator<T>::operator!=(const HeapIterator<T>& other) const {
    return index != other.index;  // Compare the current index with another iterator's index
}

template <typename T>
void HeapIterator<T>::setEndIterator(size_t idx) {
    index = idx;  // Set the end iterator index
}

template <typename T>
const std::vector<Node<T>*>& HeapIterator<T>::getHeap() const {
    return heap;  // Return the vector representing the heap
}

template <typename T>
void HeapIterator<T>::heapify() {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapify_down(i);  // Maintain the heap property from bottom up
    }
}

template <typename T>
void HeapIterator<T>::heapify_down(size_t idx) {
    size_t smallest = idx;
    size_t left = 2 * idx + 1;
    size_t right = 2 * idx + 2;

    if (left < heap.size() && heap[left]->value < heap[smallest]->value) {
        smallest = left;  // Find the smallest value among the node and its children
    }
    if (right < heap.size() && heap[right]->value < heap[smallest]->value) {
        smallest = right;
    }
    if (smallest != idx) {
        std::swap(heap[idx], heap[smallest]);  // Swap the node with the smallest child
        heapify_down(smallest);  // Recursively heapify the affected sub-tree
    }
}

#endif // HEAP_ITERATOR_TPP
