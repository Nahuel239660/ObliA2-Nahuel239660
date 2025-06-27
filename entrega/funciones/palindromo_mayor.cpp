#include "palindromo_mayor.h"

// Implementación de funciones para palíndromos
// Autor: Estudiante
// Fecha: 2024

bool esPalindromo(int num) {
    return num == obtenerReverso(num);
}

int obtenerReverso(int num) {
    int reverso = 0;
    while (num > 0) {
        reverso = reverso * 10 + num % 10;
        num /= 10;
    }
    return reverso;
}

int encontrarPalindromoMayor(int* arr, int size) {
    int maxPalindromo = -1;
    
    for (int i = 0; i < size; i++) {
        if (esPalindromo(arr[i]) && arr[i] > maxPalindromo) {
            maxPalindromo = arr[i];
        }
    }
    
    return maxPalindromo;
} 