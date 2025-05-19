#include "GraphCycleDetector.h"

GraphCycleDetector::GraphCycleDetector(int vertices) : V(vertices), adjList(vertices + 1) {}

void GraphCycleDetector::addEdge(int from, int to) {
    adjList[from].push_back(to);
}

bool GraphCycleDetector::dfs(int u, std::vector<bool>& visited, std::vector<bool>& inStack) {
    visited[u] = true;
    inStack[u] = true;

    for (int v : adjList[u]) {
        if (!visited[v]) {
            if (dfs(v, visited, inStack)) return true;
        } else if (inStack[v]) {
            return true;
        }
    }

    inStack[u] = false;
    return false;
}

bool GraphCycleDetector::hasCycle() {
    std::vector<bool> visited(V + 1, false);
    std::vector<bool> inStack(V + 1, false);

    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            if (dfs(i, visited, inStack)) return true;
        }
    }
    return false;
}
