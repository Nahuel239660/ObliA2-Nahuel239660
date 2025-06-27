#include <iostream>
#include "tads/Graph.h"
#include "tads/Graph.cpp"

int main() {
    int V, E;
    std::cin >> V >> E;

    // Crear grafo
    Graph g(V);

    // Leer aristas
    for (int i = 0; i < E; ++i) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        g.addEdge(from, to, cost);
    }

    int N;
    std::cin >> N;
    
    // Array dinámico para los vértices origen
    int* sources = new int[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> sources[i];
    }

    // Calcular caminos más cortos desde cada vértice origen
    for (int i = 0; i < N; ++i) {
        int u = sources[i];
        int* dist = g.dijkstra(u);
        
        // Imprimir distancias
        for (int v = 1; v <= g.getVertexCount(); ++v) {
            if (v == u || dist[v] == 2147483647) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << dist[v] << std::endl;
            }
        }
        
        delete[] dist;
    }

    delete[] sources;
    return 0;
} 