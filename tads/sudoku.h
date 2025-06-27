#ifndef SUDOKU_H
#define SUDOKU_H

// TAD para el tablero de Sudoku generalizado
struct Sudoku {
    int filas, columnas; // dimensiones del tablero
    int bloqueFilas, bloqueColumnas; // dimensiones de cada bloque
    int** tablero; // tablero dinámico para soportar cualquier dimensión
};

// Prototipos de funciones
bool esValido(Sudoku& s, int fila, int col, int valor);
bool resolverSudoku(Sudoku& s, int fila, int col);
void imprimirTablero(const Sudoku& s);
void inicializarTablero(Sudoku& s);
void liberarTablero(Sudoku& s);

#endif 