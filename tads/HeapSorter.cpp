#include "HeapSorter.h"

void heapifyDown(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

void buildHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyDown(arr, n, i);
    }
}

void HeapSorter::sort(std::vector<int>& arr) {
    int n = arr.size();
    buildHeap(arr);
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}
