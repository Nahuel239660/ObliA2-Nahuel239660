#include "../tads/sudoku.h"
#include <cstring>
#include <iostream>

// Inicializa el tablero dinámico según las dimensiones
void inicializarTablero(Sudoku& s) {
    s.tablero = new int*[s.filas];
    for (int i = 0; i < s.filas; i++) {
        s.tablero[i] = new int[s.columnas];
        for (int j = 0; j < s.columnas; j++)
            s.tablero[i][j] = 0;
    }
}

// Libera la memoria del tablero dinámico
void liberarTablero(Sudoku& s) {
    for (int i = 0; i < s.filas; i++)
        delete[] s.tablero[i];
    delete[] s.tablero;
}

// Verifica si es válido colocar 'valor' en (fila, col)
bool esValido(Sudoku& s, int fila, int col, int valor) {
    // Chequear fila y columna
    for (int i = 0; i < s.columnas; i++)
        if (s.tablero[fila][i] == valor) return false;
    for (int i = 0; i < s.filas; i++)
        if (s.tablero[i][col] == valor) return false;
    // Chequear bloque
    int startFila = (fila / s.bloqueFilas) * s.bloqueFilas;
    int startCol = (col / s.bloqueColumnas) * s.bloqueColumnas;
    for (int i = 0; i < s.bloqueFilas; i++)
        for (int j = 0; j < s.bloqueColumnas; j++)
            if (s.tablero[startFila + i][startCol + j] == valor) return false;
    return true;
}

// Backtracking para resolver el Sudoku
bool resolverSudoku(Sudoku& s, int fila, int col) {
    if (fila == s.filas) return true; // Terminé
    int sigFila = (col + 1 == s.columnas) ? fila + 1 : fila;
    int sigCol = (col + 1) % s.columnas;
    if (s.tablero[fila][col] != 0)
        return resolverSudoku(s, sigFila, sigCol);
    // El valor máximo es el máximo entre filas y columnas
    int maxValor = (s.filas > s.columnas) ? s.filas : s.columnas;
    for (int v = 1; v <= maxValor; v++) {
        if (esValido(s, fila, col, v)) {
            s.tablero[fila][col] = v;
            if (resolverSudoku(s, sigFila, sigCol)) return true;
            s.tablero[fila][col] = 0;
        }
    }
    return false;
}

// Imprime el tablero en el formato pedido
void imprimirTablero(const Sudoku& s) {
    for (int i = 0; i < s.filas; i++) {
        for (int j = 0; j < s.columnas; j++) {
            if (j > 0) std::cout << ' ';
            std::cout << s.tablero[i][j];
        }
        std::cout << std::endl;
    }
} 