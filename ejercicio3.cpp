#include <iostream>
#include "tads/HeapSorter.h"
#include "tads/HeapSorter.cpp"

int main() {
    int N;
    // Leer la cantidad de números
    std::cin >> N;

    // Crear array dinámico para los números
    int* nums = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    // Ordenar usando heapsort
    HeapSorter::sort(nums, N);

    // Imprimir los números ordenados
    for (int i = 0; i < N; ++i) {
        std::cout << nums[i] << "\r\n";
    }

    // Liberar memoria
    delete[] nums;
    return 0;
}
