// ejercicio1.cpp
// Obligatorio Algoritmos 2 - Ejercicio 1
// Cuenta correos únicos usando tabla hash abierta (encadenamiento)

#include <iostream>
#include <string>
#include "tads/HashTable.h"

int main() {
    int N;
    std::cin >> N;

    // Tabla hash con tamaño primo mayor a 1e5 para minimizar colisiones
    HashTable* tabla = new HashTable(200003);
    int cantidadUnicos = 0;

    for (int i = 0; i < N; ++i) {
        std::string email;
        std::cin >> email;
        // Solo cuento si no estaba antes
        if (tabla->insert(email)) {
            cantidadUnicos++;
        }
    }

    std::cout << cantidadUnicos << std::endl;

    delete tabla;
    return 0;
}
