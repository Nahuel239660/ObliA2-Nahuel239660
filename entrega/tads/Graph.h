#ifndef GRAPH_H
#define GRAPH_H

// TAD Grafo Dirigido y Ponderado
// Autor: Estudiante
// Fecha: 2024

// Estructura para representar una arista
struct Edge {
    int to;
    int cost;
    Edge* next;
    
    Edge(int t, int c) : to(t), cost(c), next(nullptr) {}
};

// Estructura para el heap (cola de prioridad)
struct HeapNode {
    int distance;
    int vertex;
};

class Graph {
private:
    int V; // cantidad de vértices
    Edge** adjList; // array de listas de adyacencia
    
    // Funciones auxiliares para el heap
    void heapify(HeapNode* heap, int size, int index);
    void insertHeap(HeapNode* heap, int& size, int distance, int vertex);
    HeapNode extractMin(HeapNode* heap, int& size);
    void swap(HeapNode& a, HeapNode& b);

public:
    // Constructor
    Graph(int vertices);
    
    // Destructor
    ~Graph();

    // Agregar arista
    void addEdge(int from, int to, int cost);

    // Algoritmo de Dijkstra
    int* dijkstra(int source);

    // Obtener cantidad de vértices
    int getVertexCount() const;
};

#endif 