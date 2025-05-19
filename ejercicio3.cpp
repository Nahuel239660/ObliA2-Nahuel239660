#include "tads/HeapSorter.h"
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) std::cin >> nums[i];

    HeapSorter::sort(nums);

    for (int x : nums) std::cout << x << std::endl;
    return 0;
}
