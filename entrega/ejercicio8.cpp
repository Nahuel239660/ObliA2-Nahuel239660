#include <iostream>
#include <cstring>
#include "funciones/grep_simple.h"
#include "funciones/grep_simple.cpp"

int main() {
    char texto[1001];
    char patron[101];
    
    // Leer texto y patrón
    std::cin.getline(texto, 1001);
    std::cin.getline(patron, 101);
    
    // Buscar patrón en el texto
    bool encontrado = buscarPatron(texto, patron);
    
    // Imprimir resultado
    if (encontrado) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
} 