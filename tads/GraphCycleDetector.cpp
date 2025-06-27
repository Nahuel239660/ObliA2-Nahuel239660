#include "GraphCycleDetector.h"
#include <iostream>

GraphCycleDetector::GraphCycleDetector(int vertices) : V(vertices) {
    adjList = new Edge*[vertices + 1]; // 1-indexed
    color = new int[vertices + 1];
    
    for (int i = 0; i <= vertices; ++i) {
        adjList[i] = nullptr;
        color[i] = 0; // blanco
    }
}

GraphCycleDetector::~GraphCycleDetector() {
    for (int i = 1; i <= V; ++i) {
        Edge* current = adjList[i];
        while (current != nullptr) {
            Edge* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] adjList;
    delete[] color;
}

void GraphCycleDetector::addEdge(int from, int to) {
    Edge* newEdge = new Edge(to);
    newEdge->next = adjList[from];
    adjList[from] = newEdge;
}

bool GraphCycleDetector::dfs(int u) {
    color[u] = 1; // gris (en proceso)
    
    Edge* edge = adjList[u];
    while (edge != nullptr) {
        int v = edge->to;
        
        if (color[v] == 0) { // blanco
            if (dfs(v)) return true;
        } else if (color[v] == 1) { // gris - encontramos un ciclo
            return true;
        }
        // si es negro, ya fue procesado completamente
        
        edge = edge->next;
    }
    
    color[u] = 2; // negro (completado)
    return false;
}

bool GraphCycleDetector::hasCycle() {
    // Resetear colores
    for (int i = 1; i <= V; ++i) {
        color[i] = 0; // blanco
    }
    
    // DFS desde cada vértice no visitado
    for (int i = 1; i <= V; ++i) {
        if (color[i] == 0) { // blanco
            if (dfs(i)) {
                return true;
            }
        }
    }
    
    return false;
}
