/*
 * Ejercicio 10 - Sudoku Generalizado
 * Autor: Estudiante
 * Fecha: 2024
 * 
 * Este programa resuelve un Sudoku generalizado usando
 * backtracking.
 */

#include <iostream>
#include "funciones/sudoku.h"
#include "funciones/sudoku.cpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int tamano = n * m;
    
    // Crear tablero dinámicamente
    int** tablero = new int*[tamano];
    for (int i = 0; i < tamano; i++) {
        tablero[i] = new int[tamano];
    }
    
    // Leer tablero inicial
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            std::cin >> tablero[i][j];
        }
    }
    
    // Resolver Sudoku
    bool resuelto = resolverSudoku(tablero, n, m);
    
    if (resuelto) {
        // Imprimir solución
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                std::cout << tablero[i][j];
                if (j < tamano - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "NO SOLUTION" << std::endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < tamano; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
    
    return 0;
} 