#include <lib-algo-ds/sort.h>

void sort::bubbleSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return;
    }
    
    bool swapped = true;
    // repeat until no value is swapped
    while (swapped) {
        swapped = false;
        // Iterate over array till second last value
        for (auto it = begin; it < end - 1; ++it) {
        // if current_value > next_value
            if (*it > *(it + 1)) {
                auto temp = *it;
                *it = *(it + 1);
                *(it + 1) = temp;
                //  set flag to mark that value was swapped
                swapped = true;
            }
        }
    }
}