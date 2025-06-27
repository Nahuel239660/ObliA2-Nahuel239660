#ifndef HEAP_SORTER_H
#define HEAP_SORTER_H

// TAD Heap Sorter para ordenamiento
// Autor: Estudiante
// Fecha: 2024

class HeapSorter {
private:
    int* heap;
    int size;
    
    // Funciones auxiliares del heap
    void heapify(int index);
    void buildHeap();
    int parent(int index) const;
    int leftChild(int index) const;
    int rightChild(int index) const;

public:
    // Constructor
    HeapSorter(int* array, int n);
    
    // Destructor
    ~HeapSorter();
    
    // Ordenamiento
    void heapSort();
    
    // Obtener array ordenado
    int* getArray() const;
};

#endif 