#include <iostream>
#include <cstring>
#include "tads/HashTable.h"
#include "tads/HashTable.cpp"
#include "tads/List.h"
#include "tads/ListImp.cpp"

int main() {
    int N;
    std::cin >> N;
    
    // Crear tabla hash para almacenar emails únicos
    HashTable emailTable;
    
    bool todosUnicos = true;
    
    for (int i = 0; i < N; i++) {
        char email[101];
        std::cin >> email;
        
        // Convertir email a un entero para usar como clave
        int hashValue = 0;
        for (int j = 0; email[j] != '\0'; j++) {
            hashValue = (hashValue * 31 + email[j]) % 1000000007;
        }
        
        // Verificar si el email ya existe
        if (emailTable.contains(hashValue)) {
            todosUnicos = false;
        } else {
            emailTable.insert(hashValue);
        }
    }
    
    // Imprimir resultado
    if (todosUnicos) {
        std::cout << "UNIQUE" << std::endl;
    } else {
        std::cout << "DUPLICATE" << std::endl;
    }
    
    return 0;
} 