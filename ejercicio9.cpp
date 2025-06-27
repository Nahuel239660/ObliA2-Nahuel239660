#include <iostream>
#include "tads/ejercicio9.h"
#include "funciones/mochila_2d.h"
using namespace std;

int main() {
    int N, S, L;
    // Leer la cantidad de archivos, el tamaño máximo y la cantidad máxima de líneas
    cin >> N >> S >> L;
    
    // Reservar memoria para los archivos
    Archivo* archivos = new Archivo[N];
    // Leer los datos de cada archivo: tamaño, líneas y puntaje
    for (int i = 0; i < N; i++) {
        cin >> archivos[i].tamano >> archivos[i].lineas >> archivos[i].puntaje;
    }
    
    // Llamar a la función que resuelve el problema de la mochila 2D
    int puntajeMaximo = mochila2D(archivos, N, S, L);
    
    // Imprimir el puntaje máximo alcanzable
    cout << puntajeMaximo << endl;
    // Liberar la memoria reservada para los archivos
    delete[] archivos;
    return 0;
}