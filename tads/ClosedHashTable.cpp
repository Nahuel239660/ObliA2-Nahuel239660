#include "ClosedHashTable.h"
#include <cmath>

ClosedHashTable::ClosedHashTable(unsigned int cap) : capacity(cap), size(0) {
    table = new std::string[capacity];
    occupied = new bool[capacity];
    for (unsigned int i = 0; i < capacity; ++i) {
        occupied[i] = false;
    }
}

ClosedHashTable::~ClosedHashTable() {
    delete[] table;
    delete[] occupied;
}

unsigned int ClosedHashTable::hash1(const std::string& key) {
    unsigned int hash = 0;
    for (char c : key) {
        hash = (hash * 131 + c) % capacity;
    }
    return hash;
}

unsigned int ClosedHashTable::hash2(const std::string& key) {
    unsigned int hash = 0;
    for (char c : key) {
        hash = (hash * 137 + c) % (capacity - 1);
    }
    return (hash == 0) ? 1 : hash;
}

bool ClosedHashTable::isPrime(unsigned int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (unsigned int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

unsigned int ClosedHashTable::nextPrime(unsigned int n) {
    while (!isPrime(n)) ++n;
    return n;
}

void ClosedHashTable::rehash() {
    unsigned int oldCapacity = capacity;
    capacity = nextPrime(capacity * 2);

    std::string* oldTable = table;
    bool* oldOccupied = occupied;

    table = new std::string[capacity];
    occupied = new bool[capacity];
    for (unsigned int i = 0; i < capacity; ++i) occupied[i] = false;

    size = 0;
    for (unsigned int i = 0; i < oldCapacity; ++i) {
        if (oldOccupied[i]) insert(oldTable[i]);
    }

    delete[] oldTable;
    delete[] oldOccupied;
}

void ClosedHashTable::insert(const std::string& key) {
    if (size * 100 / capacity > 70) rehash();

    unsigned int idx = hash1(key);
    unsigned int step = hash2(key);

    for (unsigned int i = 0; i < capacity; ++i) {
        unsigned int pos = (idx + i * step) % capacity;
        if (!occupied[pos]) {
            table[pos] = key;
            occupied[pos] = true;
            size++;
            return;
        } else if (table[pos] == key) {
            return; // ya está
        }
    }
}

bool ClosedHashTable::contains(const std::string& key) {
    unsigned int idx = hash1(key);
    unsigned int step = hash2(key);

    for (unsigned int i = 0; i < capacity; ++i) {
        unsigned int pos = (idx + i * step) % capacity;
        if (!occupied[pos]) return false;
        if (table[pos] == key) return true;
    }
    return false;
}