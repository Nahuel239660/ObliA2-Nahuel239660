#include <iostream>
#include "tads/GraphCycleDetector.h"
#include "tads/GraphCycleDetector.cpp"

int main() {
    int V, E;
    std::cin >> V >> E;

    // Crear detector de ciclos
    GraphCycleDetector g(V);

    // Leer aristas del grafo
    for (int i = 0; i < E; ++i) {
        int from, to;
        std::cin >> from >> to;
        g.addEdge(from, to);
    }

    // Verificar si hay ciclos
    bool tieneCiclos = g.hasCycle();
    
    // Imprimir resultado
    std::cout << (tieneCiclos ? 1 : 0);

    return 0;
} 