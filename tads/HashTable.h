#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "ListImp.cpp"

// Tabla hash abierta usando ListImp<string> como manejo de colisiones
class HashTable {
private:
    List<std::string>** table;
    unsigned int capacity;

    // pre: -
    // post: devuelve un índice válido en la tabla para un string
    unsigned int hash(const std::string& val);

public:
    // pre: size > 0
    // post: crea una tabla hash vacía
    HashTable(unsigned int size);

    // pre: -
    // post: libera la memoria utilizada
    ~HashTable();

    // pre: -
    // post: devuelve true si el valor se insertó (no estaba), false si ya existía
    bool insert(const std::string& val);
};

#endif
