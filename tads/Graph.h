#ifndef GRAPH_H
#define GRAPH_H

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
    // pre: V > 0
    // post: crea grafo con V vértices (1-indexed)
    Graph(int vertices);
    
    // post: libera memoria
    ~Graph();

    // pre: 1 <= from, to <= V
    // post: agrega arista dirigida de from a to con costo
    void addEdge(int from, int to, int cost);

    // pre: 1 <= source <= V
    // post: devuelve array con los costos mínimos desde source
    int* dijkstra(int source);

    // post: devuelve cantidad de vértices
    int getVertexCount() const;
};

#endif
