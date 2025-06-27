#include "Graph.h"
#include <iostream>

const int INF = 2147483647; // INT_MAX

Graph::Graph(int vertices) : V(vertices) {
    adjList = new Edge*[vertices + 1]; // 1-indexed
    for (int i = 0; i <= vertices; ++i) {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 1; i <= V; ++i) {
        Edge* current = adjList[i];
        while (current != nullptr) {
            Edge* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(int from, int to, int cost) {
    Edge* newEdge = new Edge(to, cost);
    newEdge->next = adjList[from];
    adjList[from] = newEdge;
}

void Graph::swap(HeapNode& a, HeapNode& b) {
    HeapNode temp = a;
    a = b;
    b = temp;
}

void Graph::heapify(HeapNode* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].distance < heap[smallest].distance) {
        smallest = left;
    }

    if (right < size && heap[right].distance < heap[smallest].distance) {
        smallest = right;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void Graph::insertHeap(HeapNode* heap, int& size, int distance, int vertex) {
    size++;
    int i = size - 1;
    heap[i].distance = distance;
    heap[i].vertex = vertex;

    while (i != 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode Graph::extractMin(HeapNode* heap, int& size) {
    if (size == 1) {
        size--;
        return heap[0];
    }

    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(heap, size, 0);

    return root;
}

int* Graph::dijkstra(int source) {
    int* dist = new int[V + 1];
    bool* visited = new bool[V + 1];
    
    // Inicializar distancias
    for (int i = 1; i <= V; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    // Heap para cola de prioridad
    HeapNode* heap = new HeapNode[V];
    int heapSize = 0;
    
    insertHeap(heap, heapSize, 0, source);

    while (heapSize > 0) {
        HeapNode current = extractMin(heap, heapSize);
        int u = current.vertex;
        int d = current.distance;

        if (visited[u]) continue;
        visited[u] = true;

        // Explorar vecinos
        Edge* edge = adjList[u];
        while (edge != nullptr) {
            int v = edge->to;
            int cost = edge->cost;

            if (!visited[v] && dist[u] != INF && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                insertHeap(heap, heapSize, dist[v], v);
            }
            edge = edge->next;
        }
    }

    delete[] heap;
    delete[] visited;
    return dist;
}

int Graph::getVertexCount() const {
    return V;
}
