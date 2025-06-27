#include <iostream>
#include "funciones/palindromo_mayor.h"
#include "funciones/palindromo_mayor.cpp"

int main() {
    int N;
    std::cin >> N;
    
    // Leer array de números
    int* numeros = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> numeros[i];
    }
    
    // Encontrar el palíndromo mayor
    int resultado = encontrarPalindromoMayor(numeros, N);
    
    // Imprimir resultado
    std::cout << resultado << std::endl;
    
    delete[] numeros;
    return 0;
} 