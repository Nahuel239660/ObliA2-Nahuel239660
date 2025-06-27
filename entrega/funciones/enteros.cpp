// Funciones auxiliares para manejo de enteros
// Autor: Estudiante
// Fecha: 2024

#include <iostream>

// Función para intercambiar dos valores enteros
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para encontrar el máximo entre dos enteros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función para encontrar el mínimo entre dos enteros
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Función para calcular el valor absoluto
int abs(int x) {
    return (x < 0) ? -x : x;
} 