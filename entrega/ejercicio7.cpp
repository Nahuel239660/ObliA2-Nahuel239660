#include <iostream>
#include "funciones/skyline.h"
#include "funciones/skyline.cpp"

int main() {
    int N;
    std::cin >> N;
    
    // Leer edificios
    Edificio* edificios = new Edificio[N];
    for (int i = 0; i < N; i++) {
        std::cin >> edificios[i].inicio >> edificios[i].fin >> edificios[i].altura;
    }
    
    // Calcular skyline
    int puntos;
    PuntoSkyline* skyline = calcularSkyline(edificios, N, puntos);
    
    // Imprimir resultado
    for (int i = 0; i < puntos; i++) {
        std::cout << skyline[i].x << " " << skyline[i].altura << std::endl;
    }
    
    delete[] edificios;
    delete[] skyline;
    return 0;
} 