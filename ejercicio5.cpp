#include <iostream>
#include "tads/GraphCycleDetector.h"

int main() {
    int V, E;
    std::cin >> V >> E;

    GraphCycleDetector g(V);

    for (int i = 0; i < E; ++i) {
        int from, to;
        std::cin >> from >> to;
        g.addEdge(from, to);
    }

    std::cout << (g.hasCycle() ? 1 : 0) << std::endl;

    return 0;
}
