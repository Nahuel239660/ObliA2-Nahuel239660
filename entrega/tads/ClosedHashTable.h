#ifndef CLOSED_HASH_TABLE_H
#define CLOSED_HASH_TABLE_H

// TAD Tabla Hash con Direccionamiento Cerrado y Doble Hashing

class ClosedHashTable {
private:
    int* table;
    bool* occupied;
    int capacity;
    int size;
    
    // Funciones hash
    int hash1(int key) const;
    int hash2(int key) const;
    
    // Función para encontrar la siguiente posición
    int findPosition(int key) const;

public:
    // Constructor
    ClosedHashTable(int initialCapacity = 100);
    
    // Destructor
    ~ClosedHashTable();
    
    // Operaciones básicas
    void insert(int key);
    bool contains(int key) const;
    bool remove(int key);
    int getSize() const;
    bool isEmpty() const;
};

#endif 