#include <iostream>
#include <string>
#include "tads/ClosedHashTable.h"
#include "tads/ClosedHashTable.cpp"

int main() {
    int N;
    // Leer la cantidad de palabras en el diccionario
    std::cin >> N;

    // Crear tabla hash cerrada con doble hashing para resolver colisiones
    // Usar un tamaño de tabla más grande para evitar colisiones excesivas
    ClosedHashTable tabla(4000003); // número primo grande > 2e6

    // Leer e insertar todas las palabras del diccionario
    for (int i = 0; i < N; ++i) {
        std::string palabra;
        std::cin >> palabra;
        tabla.insert(palabra);
    }

    int M;
    // Leer la cantidad de palabras a consultar
    std::cin >> M;

    // Para cada palabra de consulta, verificar si existe en el diccionario
    for (int i = 0; i < M; ++i) {
        std::string palabra;
        std::cin >> palabra;
        // Imprimir 1 si existe, 0 si no existe
        std::cout << (tabla.contains(palabra) ? 1 : 0) << "\r\n";
    }

    return 0;
}
