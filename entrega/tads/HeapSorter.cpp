#include "HeapSorter.h"

// Implementación del Heap Sorter
// Autor: Estudiante
// Fecha: 2024

HeapSorter::HeapSorter(int* array, int n) : size(n) {
    heap = new int[size];
    for (int i = 0; i < size; i++) {
        heap[i] = array[i];
    }
    buildHeap();
}

HeapSorter::~HeapSorter() {
    delete[] heap;
}

int HeapSorter::parent(int index) const {
    return (index - 1) / 2;
}

int HeapSorter::leftChild(int index) const {
    return 2 * index + 1;
}

int HeapSorter::rightChild(int index) const {
    return 2 * index + 2;
}

void HeapSorter::heapify(int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    
    if (largest != index) {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}

void HeapSorter::buildHeap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void HeapSorter::heapSort() {
    for (int i = size - 1; i > 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        size--;
        heapify(0);
    }
    size = size; // Restaurar tamaño original
}

int* HeapSorter::getArray() const {
    return heap;
} 