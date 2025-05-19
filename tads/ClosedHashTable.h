#ifndef CLOSEDHASHTABLE_H
#define CLOSEDHASHTABLE_H

#include <string>

class ClosedHashTable {
private:
    std::string* table;
    bool* occupied;
    unsigned int capacity;
    unsigned int size;

    unsigned int hash1(const std::string& key);
    unsigned int hash2(const std::string& key);

    void rehash();
    bool isPrime(unsigned int n);
    unsigned int nextPrime(unsigned int n);

public:
    // pre: cap > 0
    // post: crea tabla vacía con capacidad inicial
    ClosedHashTable(unsigned int cap = 1031);

    // pre: -
    // post: libera recursos
    ~ClosedHashTable();

    // pre: -
    // post: inserta si no existía
    void insert(const std::string& key);

    // pre: -
    // post: true si existe
    bool contains(const std::string& key);
};

#endif