#ifndef EJERCICIO6_H
#define EJERCICIO6_H

// TAD específico para Ejercicio 6 - Palíndromo Mayor
// Autor: Estudiante
// Fecha: 2024

class PalindromoFinder {
private:
    int* numbers;
    int size;
    
    // Función para verificar si un número es palíndromo
    bool esPalindromo(int num) const;
    
    // Función para obtener el reverso de un número
    int obtenerReverso(int num) const;

public:
    // Constructor
    PalindromoFinder(int* arr, int n);
    
    // Destructor
    ~PalindromoFinder();
    
    // Encontrar el palíndromo mayor
    int encontrarPalindromoMayor() const;
};

#endif 