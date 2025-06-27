#include "HeapSorter.h"

// Función auxiliar para intercambiar elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función heapify para mantener la propiedad del heap
void heapifyDown(int* arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

// Construir el heap desde el array
void buildHeap(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyDown(arr, n, i);
    }
}

void HeapSorter::sort(int* arr, int n) {
    // Construir el heap
    buildHeap(arr, n);
    
    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}
