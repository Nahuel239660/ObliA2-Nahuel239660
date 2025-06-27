#include "HashTable.h"

// Implementación de Tabla Hash con Direccionamiento Abierto

HashTable::HashTable(int initialCapacity) : capacity(initialCapacity), size(0) {
    table = new List<int>[capacity];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hash(int key) const {
    return abs(key) % capacity;
}

void HashTable::resize() {
    int oldCapacity = capacity;
    List<int>* oldTable = table;
    
    capacity *= 2;
    table = new List<int>[capacity];
    size = 0;
    
    // Reinsertar todos los elementos
    for (int i = 0; i < oldCapacity; i++) {
        Node<int>* current = oldTable[i].getHead();
        while (current != nullptr) {
            insert(current->data);
            current = current->next;
        }
    }
    
    delete[] oldTable;
}

void HashTable::insert(int key) {
    if (size >= capacity / 2) {
        resize();
    }
    
    int index = hash(key);
    if (!table[index].contains(key)) {
        table[index].insert(key);
        size++;
    }
}

bool HashTable::contains(int key) const {
    int index = hash(key);
    return table[index].contains(key);
}

bool HashTable::remove(int key) {
    int index = hash(key);
    if (table[index].remove(key)) {
        size--;
        return true;
    }
    return false;
}

int HashTable::getSize() const {
    return size;
}

bool HashTable::isEmpty() const {
    return size == 0;
} 