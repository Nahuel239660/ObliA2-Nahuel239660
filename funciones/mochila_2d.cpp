#include "../tads/ejercicio9.h"
#include <cstring>

// Resuelve el problema de la mochila 2D (restricción de tamaño y líneas) usando programación dinámica
// archivos: arreglo de archivos con sus atributos (tamaño, líneas, puntaje)
// N: cantidad de archivos
// S: tamaño máximo permitido (MB)
// L: cantidad máxima de líneas permitidas
int mochila2D(Archivo* archivos, int N, int S, int L) {
    // Creamos la matriz DP: dp[s][l] = máximo puntaje usando hasta s MB y l líneas
    int** dp = new int*[S+1];
    for (int s = 0; s <= S; s++) {
        dp[s] = new int[L+1];
        // Inicializamos en 0 (ningún archivo seleccionado)
        memset(dp[s], 0, (L+1)*sizeof(int));
    }
    
    // Iteramos sobre cada archivo
    for (int i = 0; i < N; i++) {
        // Recorremos de mayor a menor para no reutilizar el mismo archivo varias veces
        for (int s = S; s >= archivos[i].tamano; s--) {
            for (int l = L; l >= archivos[i].lineas; l--) {
                // Si agregamos el archivo i, actualizamos el puntaje si es mejor
                int nuevo = dp[s - archivos[i].tamano][l - archivos[i].lineas] + archivos[i].puntaje;
                if (nuevo > dp[s][l]) dp[s][l] = nuevo;
            }
        }
    }
    
    // Buscamos el máximo puntaje alcanzable
    int res = 0;
    for (int s = 0; s <= S; s++) {
        for (int l = 0; l <= L; l++) {
            if (dp[s][l] > res) res = dp[s][l];
        }
    }
    
    // Liberamos la memoria utilizada
    for (int s = 0; s <= S; s++) delete[] dp[s];
    delete[] dp;
    return res;
} 