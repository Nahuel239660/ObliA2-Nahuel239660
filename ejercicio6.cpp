// ejercicio6.cpp
// Entrada/salida y llamado a la función de skyline
#include <iostream>
#include "tads/ejercicio6.h"
#include "funciones/skyline.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    // Reservar memoria dinámicamente para los edificios
    Edificio* edificios = new Edificio[N];
    for (int i = 0; i < N; i++) {
        cin >> edificios[i].inicio >> edificios[i].fin >> edificios[i].altura;
    }
    // Reservar memoria dinámicamente para la silueta (máximo 2*N puntos)
    Punto* silueta = new Punto[2*N];
    int nSilueta;
    // Llamo a la función que resuelve el skyline
    skyline(edificios, 0, N-1, silueta, nSilueta);
    // Imprimo la silueta, omitiendo (0,0)
    for (int i = 0; i < nSilueta; i++) {
        if (silueta[i].x == 0 && silueta[i].altura == 0) continue;
        cout << silueta[i].x << " " << silueta[i].altura << endl;
    }
    // Liberar memoria
    delete[] edificios;
    delete[] silueta;
    return 0;
}