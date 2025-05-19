#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility> // para std::pair

class Graph {
private:
    int V; // cantidad de vértices
    std::vector<std::vector<std::pair<int, int>>> adjList; // lista de adyacencia: destino, costo

public:
    // pre: V > 0
    // post: crea grafo con V vértices (1-indexed)
    Graph(int vertices);

    // pre: 1 <= from, to <= V
    // post: agrega arista dirigida de from a to con costo
    void addEdge(int from, int to, int cost);

    // pre: 1 <= source <= V
    // post: devuelve vector con los costos mínimos desde source
    std::vector<int> dijkstra(int source);

    // post: devuelve cantidad de vértices
    int getVertexCount() const;
};

#endif
