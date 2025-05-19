#include "Graph.h"
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

Graph::Graph(int vertices) : V(vertices), adjList(vertices + 1) {} // 1-indexed

void Graph::addEdge(int from, int to, int cost) {
    adjList[from].emplace_back(to, cost);
}

std::vector<int> Graph::dijkstra(int source) {
    std::vector<int> dist(V + 1, INF);
    dist[source] = 0;

    using pii = std::pair<int, int>; // (dist, vertex)
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (size_t i = 0; i < adjList[u].size(); ++i) {
            int v = adjList[u][i].first;
            int cost = adjList[u][i].second;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int Graph::getVertexCount() const {
    return V;
}
