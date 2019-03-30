#include <lib-algo-ds/sort.h>

void sort::insertionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return;
    }

    // Iterate over the input starting at the second element
    for (auto it = begin + 1; it < end; ++it) {
    // Insert every element into the sorted subarray at the correct position
    // after every i'th iteration the sorted array size will be i + 1
        auto current_element_position = it;
        while (current_element_position != begin && *current_element_position < *(current_element_position - 1)) {
            // swap
            auto temp = *current_element_position;
            *current_element_position = *(current_element_position - 1);
            *(current_element_position - 1) = temp;
            --current_element_position;
        }
    }
}