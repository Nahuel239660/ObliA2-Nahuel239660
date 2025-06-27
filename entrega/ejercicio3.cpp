#include <iostream>
#include "tads/HeapSorter.h"
#include "tads/HeapSorter.cpp"
#include "funciones/enteros.cpp"

int main() {
    int N;
    std::cin >> N;
    
    // Leer array de números
    int* numeros = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> numeros[i];
    }
    
    // Crear heap sorter y ordenar
    HeapSorter sorter(numeros, N);
    sorter.heapSort();
    
    // Obtener array ordenado
    int* ordenado = sorter.getArray();
    
    // Imprimir resultado
    for (int i = 0; i < N; i++) {
        std::cout << ordenado[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    delete[] numeros;
    return 0;
} 