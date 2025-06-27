#ifndef SKYLINE_H
#define SKYLINE_H

// Funciones para el problema del skyline
// Autor: Estudiante
// Fecha: 2024

// Estructura para representar un edificio
struct Edificio {
    int inicio;
    int fin;
    int altura;
};

// Estructura para representar un punto del skyline
struct PuntoSkyline {
    int x;
    int altura;
};

// Calcular el skyline de un conjunto de edificios
PuntoSkyline* calcularSkyline(Edificio* edificios, int n, int& puntos);

// Función auxiliar para ordenar edificios por inicio
void ordenarEdificios(Edificio* edificios, int n);

#endif 