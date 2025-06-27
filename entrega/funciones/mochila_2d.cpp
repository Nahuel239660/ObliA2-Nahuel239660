#include "mochila_2d.h"

// Implementación de funciones para la mochila 2D
// Autor: Estudiante
// Fecha: 2024

int mochilaDP(Objeto* objetos, int n, int capacidad, int** dp) {
    // Caso base: sin objetos o sin capacidad
    if (n == 0 || capacidad == 0) {
        return 0;
    }
    
    // Si ya calculamos este subproblema
    if (dp[n][capacidad] != -1) {
        return dp[n][capacidad];
    }
    
    // Si el objeto actual no cabe en la mochila
    if (objetos[n - 1].peso > capacidad) {
        dp[n][capacidad] = mochilaDP(objetos, n - 1, capacidad, dp);
        return dp[n][capacidad];
    }
    
    // Tomar el máximo entre incluir o no incluir el objeto actual
    int incluir = objetos[n - 1].valor + mochilaDP(objetos, n - 1, capacidad - objetos[n - 1].peso, dp);
    int noIncluir = mochilaDP(objetos, n - 1, capacidad, dp);
    
    dp[n][capacidad] = (incluir > noIncluir) ? incluir : noIncluir;
    return dp[n][capacidad];
}

int resolverMochila2D(Objeto* objetos, int n, int capacidad) {
    // Crear tabla de programación dinámica
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[capacidad + 1];
        for (int j = 0; j <= capacidad; j++) {
            dp[i][j] = -1;
        }
    }
    
    int resultado = mochilaDP(objetos, n, capacidad, dp);
    
    // Liberar memoria
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    return resultado;
} 