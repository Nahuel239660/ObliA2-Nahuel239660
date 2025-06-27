#ifndef GRAPH_CYCLE_DETECTOR_H
#define GRAPH_CYCLE_DETECTOR_H

// TAD Detector de Ciclos en Grafos Dirigidos
// Autor: Estudiante
// Fecha: 2024

// Estructura para representar una arista
struct Edge {
    int to;
    Edge* next;
    
    Edge(int t) : to(t), next(nullptr) {}
};

class GraphCycleDetector {
private:
    int V; // cantidad de vértices
    Edge** adjList; // array de listas de adyacencia
    
    // Colores para DFS: 0=blanco, 1=gris, 2=negro
    int* color;
    
    // Función DFS para detectar ciclos
    bool dfs(int u);

public:
    // Constructor
    GraphCycleDetector(int vertices);
    
    // Destructor
    ~GraphCycleDetector();

    // Agregar arista
    void addEdge(int from, int to);

    // Detectar si hay ciclos
    bool hasCycle();
};

#endif 