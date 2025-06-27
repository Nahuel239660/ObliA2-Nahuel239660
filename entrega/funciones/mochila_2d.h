#ifndef MOCHILA_2D_H
#define MOCHILA_2D_H

// Funciones para el problema de la mochila 2D
// Autor: Estudiante
// Fecha: 2024

// Estructura para representar un objeto
struct Objeto {
    int peso;
    int valor;
};

// Resolver el problema de la mochila 2D
int resolverMochila2D(Objeto* objetos, int n, int capacidad);

// Función auxiliar para el algoritmo de programación dinámica
int mochilaDP(Objeto* objetos, int n, int capacidad, int** dp);

#endif 