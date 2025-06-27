#ifndef LIST_H
#define LIST_H

// TAD Lista Enlazada Genérica

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    
    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class List {
private:
    Node<T>* head;
    int size;

public:
    // Constructor
    List();
    
    // Destructor
    ~List();
    
    // Operaciones básicas
    void insert(const T& value);
    bool remove(const T& value);
    bool contains(const T& value) const;
    int getSize() const;
    bool isEmpty() const;
    
    // Iterador simple
    Node<T>* getHead() const;
};

#endif 