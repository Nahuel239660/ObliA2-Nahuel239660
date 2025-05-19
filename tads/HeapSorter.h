#ifndef HEAPSORTER_H
#define HEAPSORTER_H

#include <vector>

class HeapSorter {
public:
    // pre: arr no vacío
    // post: ordena el vector de menor a mayor usando heapsort
    static void sort(std::vector<int>& arr);
};

#endif
