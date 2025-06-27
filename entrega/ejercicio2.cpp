#include <iostream>
#include <cstring>
#include "tads/ClosedHashTable.h"
#include "tads/ClosedHashTable.cpp"

int main() {
    int N;
    std::cin >> N;
    
    // Crear tabla hash cerrada para el diccionario
    ClosedHashTable dictionary;
    
    // Insertar palabras en el diccionario
    for (int i = 0; i < N; i++) {
        char palabra[101];
        std::cin >> palabra;
        
        // Convertir palabra a entero para usar como clave
        int hashValue = 0;
        for (int j = 0; palabra[j] != '\0'; j++) {
            hashValue = (hashValue * 31 + palabra[j]) % 1000000007;
        }
        
        dictionary.insert(hashValue);
    }
    
    int Q;
    std::cin >> Q;
    
    // Procesar consultas
    for (int i = 0; i < Q; i++) {
        char consulta[101];
        std::cin >> consulta;
        
        // Convertir consulta a entero
        int hashValue = 0;
        for (int j = 0; consulta[j] != '\0'; j++) {
            hashValue = (hashValue * 31 + consulta[j]) % 1000000007;
        }
        
        // Verificar si la palabra está en el diccionario
        if (dictionary.contains(hashValue)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
} 