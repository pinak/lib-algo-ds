#include <lib-algo-ds/sort.h>
#include <algorithm>

namespace {

    std::vector<int>::iterator partitionLomuto(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        // Pick a pivot (last element)
        auto pivot = end - 1;
        // all elements smaller than pivot move to left pivot
        // all elements larger than pivot move to right of pivot
        // using Lomuto partition scheme
        auto i = begin;
        for (auto it = begin; it < pivot; ++it) {
            if (*it < *pivot) {
                std::iter_swap(i, it);
                ++i;
            }
        }
        std::iter_swap(pivot, i);
        return i;
    }
}

void sort::quickSortLomuto(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin >= end) {
        return;
    }

    auto p = partitionLomuto(begin, end);
    quickSortLomuto(begin, p);
    quickSortLomuto(p + 1, end);
}

namespace {
    // Hoare partition
    std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        auto pivot_value = *(begin + (end - begin) / 2);
        auto forward_it = begin - 1;
        auto reverse_it = end;
        while (true) {
            do {
                ++forward_it;
            } while (*forward_it < pivot_value);
            do {
                --reverse_it;
            } while (*reverse_it > pivot_value);
            if (forward_it < reverse_it) {
                std::iter_swap(forward_it, reverse_it);
            } else {
                return forward_it;
            }
        }
    }

}

void sort::quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (end - begin < 2) {
        return;
    }

    auto p = partition(begin, end);
    quickSort(begin, p);
    quickSort(p, end);
}

