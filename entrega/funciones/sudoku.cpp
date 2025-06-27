#include "sudoku.h"

// Implementación de funciones para Sudoku generalizado
// Autor: Estudiante
// Fecha: 2024

bool esValido(int** tablero, int fila, int col, int num, int n, int m) {
    // Verificar fila
    for (int x = 0; x < n * m; x++) {
        if (tablero[fila][x] == num) {
            return false;
        }
    }
    
    // Verificar columna
    for (int x = 0; x < n * m; x++) {
        if (tablero[x][col] == num) {
            return false;
        }
    }
    
    // Verificar bloque
    int inicioFila = fila - fila % n;
    int inicioCol = col - col % m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool encontrarCeldaVacia(int** tablero, int n, int m, int& fila, int& col) {
    for (fila = 0; fila < n * m; fila++) {
        for (col = 0; col < n * m; col++) {
            if (tablero[fila][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool resolverSudoku(int** tablero, int n, int m) {
    int fila, col;
    
    if (!encontrarCeldaVacia(tablero, n, m, fila, col)) {
        return true; // Sudoku resuelto
    }
    
    for (int num = 1; num <= n * m; num++) {
        if (esValido(tablero, fila, col, num, n, m)) {
            tablero[fila][col] = num;
            
            if (resolverSudoku(tablero, n, m)) {
                return true;
            }
            
            tablero[fila][col] = 0; // Backtrack
        }
    }
    
    return false;
}

bool sudokuCompleto(int** tablero, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < n * m; j++) {
            if (tablero[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
} 