#include "skyline.h"

// Implementación de funciones para el skyline
// Autor: Estudiante
// Fecha: 2024

void ordenarEdificios(Edificio* edificios, int n) {
    // Ordenamiento simple por burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edificios[j].inicio > edificios[j + 1].inicio) {
                Edificio temp = edificios[j];
                edificios[j] = edificios[j + 1];
                edificios[j + 1] = temp;
            }
        }
    }
}

PuntoSkyline* calcularSkyline(Edificio* edificios, int n, int& puntos) {
    if (n == 0) {
        puntos = 0;
        return nullptr;
    }
    
    // Ordenar edificios por posición inicial
    ordenarEdificios(edificios, n);
    
    // Array temporal para almacenar puntos
    PuntoSkyline* temp = new PuntoSkyline[2 * n];
    puntos = 0;
    
    // Procesar cada edificio
    for (int i = 0; i < n; i++) {
        // Agregar punto de inicio si es más alto que el actual
        if (puntos == 0 || edificios[i].altura > temp[puntos - 1].altura) {
            temp[puntos].x = edificios[i].inicio;
            temp[puntos].altura = edificios[i].altura;
            puntos++;
        }
        
        // Agregar punto de fin si es necesario
        if (i == n - 1 || edificios[i].fin < edificios[i + 1].inicio) {
            temp[puntos].x = edificios[i].fin;
            temp[puntos].altura = 0;
            puntos++;
        }
    }
    
    // Crear array final
    PuntoSkyline* resultado = new PuntoSkyline[puntos];
    for (int i = 0; i < puntos; i++) {
        resultado[i] = temp[i];
    }
    
    delete[] temp;
    return resultado;
} 