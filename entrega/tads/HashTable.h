#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "List.h"

// TAD Tabla Hash con Direccionamiento Abierto

class HashTable {
private:
    List<int>* table;
    int size;
    int capacity;
    
    // Función hash simple
    int hash(int key) const;
    
    // Función para redimensionar la tabla
    void resize();

public:
    // Constructor
    HashTable(int initialCapacity = 100);
    
    // Destructor
    ~HashTable();
    
    // Operaciones básicas
    void insert(int key);
    bool contains(int key) const;
    bool remove(int key);
    int getSize() const;
    bool isEmpty() const;
};

#endif 