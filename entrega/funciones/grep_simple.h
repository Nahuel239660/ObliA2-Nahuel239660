#ifndef GREP_SIMPLE_H
#define GREP_SIMPLE_H

// Función para buscar un patrón en un texto
// pre: texto y patron no son null
// post: devuelve true si el patrón está en el texto
bool buscarPatron(const char* texto, const char* patron);

// Función para verificar si un carácter coincide con un patrón
// pre: c es un carácter válido, patron no es null
// post: devuelve true si el carácter coincide con el patrón
bool coincideCaracter(char c, const char* patron);

#endif 