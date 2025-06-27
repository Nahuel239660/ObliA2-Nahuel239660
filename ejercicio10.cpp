#include <iostream>
#include "tads/sudoku.h"
using namespace std;

int main() {
    Sudoku s;
    // Leer dimensiones del tablero
    cin >> s.filas >> s.columnas;
    // Calcular dimensiones de los bloques proporcionales
    s.bloqueFilas = s.filas / 3;
    s.bloqueColumnas = s.columnas / 3;
    // Inicializar el tablero dinámico
    inicializarTablero(s);
    // Leer el tablero
    for (int i = 0; i < s.filas; i++)
        for (int j = 0; j < s.columnas; j++)
            cin >> s.tablero[i][j];
    // Resolver el Sudoku
    resolverSudoku(s, 0, 0);
    // Imprimir el tablero resuelto
    imprimirTablero(s);
    // Liberar memoria
    liberarTablero(s);
    return 0;
}