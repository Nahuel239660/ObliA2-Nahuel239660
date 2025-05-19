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
    std::vector<int> sources(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> sources[i];
    }

    for (int u : sources) {
        std::vector<int> dist = g.dijkstra(u);
        for (int v = 1; v <= g.getVertexCount(); ++v) {
            if (v == u || dist[v] == std::numeric_limits<int>::max()) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << dist[v] << std::endl;
            }
        }
    }

    return 0;
}