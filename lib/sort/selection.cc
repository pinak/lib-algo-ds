#include <lib-algo-ds/sort.h>

void sort::selectionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

    auto length_of_already_sorted_vector = 0;

    while (length_of_already_sorted_vector != end - begin) {
        auto smallest = end;
        for (auto it = begin + length_of_already_sorted_vector; it < end; ++it) {
            if (smallest == end) {
                smallest = it;
            }
            if (*it < *smallest) {
                smallest = it;
            }
        }
        // put at end of already sorted part
        std::iter_swap(smallest, begin + length_of_already_sorted_vector);
        ++length_of_already_sorted_vector;
    }
}