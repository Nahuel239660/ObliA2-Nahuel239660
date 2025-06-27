#ifndef GRAPH_CYCLE_DETECTOR_H
#define GRAPH_CYCLE_DETECTOR_H

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
    // pre: V > 0
    // post: crea grafo con V vértices (1-indexed)
    GraphCycleDetector(int vertices);
    
    // post: libera memoria
    ~GraphCycleDetector();

    // pre: 1 <= from, to <= V
    // post: agrega arista dirigida de from a to
    void addEdge(int from, int to);

    // post: devuelve true si el grafo tiene al menos un ciclo
    bool hasCycle();
};

#endif
