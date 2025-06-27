#include "ClosedHashTable.h"

// Implementación de Tabla Hash con Direccionamiento Cerrado

ClosedHashTable::ClosedHashTable(int initialCapacity) : capacity(initialCapacity), size(0) {
    table = new int[capacity];
    occupied = new bool[capacity];
    
    for (int i = 0; i < capacity; i++) {
        occupied[i] = false;
    }
}

ClosedHashTable::~ClosedHashTable() {
    delete[] table;
    delete[] occupied;
}

int ClosedHashTable::hash1(int key) const {
    return abs(key) % capacity;
}

int ClosedHashTable::hash2(int key) const {
    return 1 + (abs(key) % (capacity - 1));
}

int ClosedHashTable::findPosition(int key) const {
    int h1 = hash1(key);
    int h2 = hash2(key);
    
    for (int i = 0; i < capacity; i++) {
        int pos = (h1 + i * h2) % capacity;
        if (!occupied[pos] || table[pos] == key) {
            return pos;
        }
    }
    return -1; // Tabla llena
}

void ClosedHashTable::insert(int key) {
    if (size >= capacity) {
        return; // Tabla llena
    }
    
    int pos = findPosition(key);
    if (pos != -1 && !occupied[pos]) {
        table[pos] = key;
        occupied[pos] = true;
        size++;
    }
}

bool ClosedHashTable::contains(int key) const {
    int pos = findPosition(key);
    return (pos != -1 && occupied[pos] && table[pos] == key);
}

bool ClosedHashTable::remove(int key) {
    int pos = findPosition(key);
    if (pos != -1 && occupied[pos] && table[pos] == key) {
        occupied[pos] = false;
        size--;
        return true;
    }
    return false;
}

int ClosedHashTable::getSize() const {
    return size;
}

bool ClosedHashTable::isEmpty() const {
    return size == 0;
} 