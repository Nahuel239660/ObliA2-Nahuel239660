#include <iostream>
#include "funciones/mochila_2d.h"
#include "funciones/mochila_2d.cpp"

int main() {
    int N, capacidad;
    std::cin >> N >> capacidad;
    
    // Leer objetos
    Objeto* objetos = new Objeto[N];
    for (int i = 0; i < N; i++) {
        std::cin >> objetos[i].peso >> objetos[i].valor;
    }
    
    // Resolver problema de la mochila
    int resultado = resolverMochila2D(objetos, N, capacidad);
    
    // Imprimir resultado
    std::cout << resultado << std::endl;
    
    delete[] objetos;
    return 0;
} 