#include <iostream>
#include "tads/Graph.h"

int main() {
    int V, E;
    std::cin >> V >> E;

    Graph g(V);

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

    for (int i = 0; i < N; ++i) {
        int u = sources[i];
        int* dist = g.dijkstra(u);
        
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