#include "List.h"

// Implementación de la Lista Enlazada

template<typename T>
List<T>::List() : head(nullptr), size(0) {}

template<typename T>
List<T>::~List() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void List<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
bool List<T>::remove(const T& value) {
    if (head == nullptr) return false;
    
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }
    
    Node<T>* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool List<T>::contains(const T& value) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
int List<T>::getSize() const {
    return size;
}

template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
Node<T>* List<T>::getHead() const {
    return head;
} 