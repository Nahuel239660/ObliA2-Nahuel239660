#ifndef GRAPH_CYCLE_DETECTOR_H
#define GRAPH_CYCLE_DETECTOR_H

#include <vector>

class GraphCycleDetector {
private:
    int V;
    std::vector<std::vector<int>> adjList;
    bool dfs(int u, std::vector<bool>& visited, std::vector<bool>& inStack);

public:
    GraphCycleDetector(int vertices);
    void addEdge(int from, int to);
    bool hasCycle();
};

#endif
