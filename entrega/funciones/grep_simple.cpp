#include "grep_simple.h"
#include <cstring>

// Función para buscar un patrón en un texto usando algoritmo simple
bool buscarPatron(const char* texto, const char* patron) {
    int lenTexto = strlen(texto);
    int lenPatron = strlen(patron);
    
    for (int i = 0; i <= lenTexto - lenPatron; i++) {
        bool coincide = true;
        for (int j = 0; j < lenPatron; j++) {
            if (texto[i + j] != patron[j]) {
                coincide = false;
                break;
            }
        }
        if (coincide) {
            return true;
        }
    }
    return false;
}

// Función para verificar si un carácter coincide con un patrón
bool coincideCaracter(char c, const char* patron) {
    int len = strlen(patron);
    for (int i = 0; i < len; i++) {
        if (c == patron[i]) {
            return true;
        }
    }
    return false;
} 