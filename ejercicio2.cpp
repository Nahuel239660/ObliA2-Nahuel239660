#include <iostream>
#include <string>
#include "tads/ClosedHashTable.h"

int main() {
    int N;
    std::cin >> N;

    ClosedHashTable tabla(2000003); // número primo grande > 1e6

    for (int i = 0; i < N; ++i) {
        std::string palabra;
        std::cin >> palabra;
        tabla.insert(palabra);
    }

    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        std::string palabra;
        std::cin >> palabra;
        std::cout << (tabla.contains(palabra) ? 1 : 0) << std::endl;
    }

    return 0;
}
