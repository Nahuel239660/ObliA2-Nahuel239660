#include "HashTable.h"

HashTable::HashTable(unsigned int size) : capacity(size) {
    table = new List<std::string>*[capacity];
    for (unsigned int i = 0; i < capacity; ++i) {
        table[i] = new ListImp<std::string>();
    }
}

HashTable::~HashTable() {
    for (unsigned int i = 0; i < capacity; ++i) {
        delete table[i];
    }
    delete[] table;
}

unsigned int HashTable::hash(const std::string& val) {
    unsigned int hash = 0;
    for (char c : val) {
        hash = (hash * 131 + c) % capacity;
    }
    return hash;
}

bool HashTable::insert(const std::string& val) {
    unsigned int idx = hash(val);
    List<std::string>* lista = table[idx];
    for (int i = 0; i < lista->getSize(); ++i) {
        if (lista->get(i) == val) {
            return false;
        }
    }
    lista->insert(val);
    return true;
}
