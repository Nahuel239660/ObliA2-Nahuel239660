// ejercicio1.cpp
// Obligatorio Algoritmos 2 - Ejercicio 1
// Cuenta correos únicos usando tabla hash abierta (encadenamiento)

#include <iostream>
#include <string>
#include "tads/HashTable.h"
#include "tads/HashTable.cpp"

int main() {
    int N;
    // Leer la cantidad de emails en la base de datos
    std::cin >> N;

    // Crear tabla hash con tamaño primo mayor a 1e5 para minimizar colisiones
    // El tamaño 200003 es un número primo que permite buena distribución
    HashTable* tabla = new HashTable(200003);
    int cantidadUnicos = 0;

    // Procesar cada email de la entrada
    for (int i = 0; i < N; ++i) {
        std::string email;
        std::cin >> email;
        // Solo incremento el contador si el email no estaba antes en la tabla
        // La función insert() devuelve true si se insertó (era nuevo), false si ya existía
        if (tabla->insert(email)) {
            cantidadUnicos++;
        }
    }

    // Imprimir la cantidad total de emails únicos encontrados
    std::cout << cantidadUnicos << std::endl;

    // Liberar la memoria utilizada por la tabla hash
    delete tabla;
    return 0;
}
