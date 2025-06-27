#ifndef SUDOKU_H
#define SUDOKU_H

// Funciones para resolver Sudoku generalizado
// Autor: Estudiante
// Fecha: 2024

// Verificar si un número es válido en una posición
bool esValido(int** tablero, int fila, int col, int num, int n, int m);

// Resolver el Sudoku usando backtracking
bool resolverSudoku(int** tablero, int n, int m);

// Verificar si el Sudoku está completo
bool sudokuCompleto(int** tablero, int n, int m);

// Encontrar la siguiente celda vacía
bool encontrarCeldaVacia(int** tablero, int n, int m, int& fila, int& col);

#endif 