#include <lib-algo-ds/sort.h>

namespace {
    void merge(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end) {
        auto left = std::vector<int>(begin, middle);
        auto right = std::vector<int>(middle, end);
        auto current_insertion_point = begin;
        auto left_it = left.begin();
        auto right_it = right.begin();
        while (left_it != left.end() && right_it != right.end()) {
            if (*left_it < *right_it) {
                *current_insertion_point = *left_it;
                ++left_it;
            } else {
                *current_insertion_point = *right_it;
                ++right_it;
            }
            ++current_insertion_point;
        }

        while (right_it != right.end()) {
            *current_insertion_point = *right_it;
            ++right_it;
            ++current_insertion_point;
        }
        
        while (left_it != left.end()) {
            *current_insertion_point = *left_it;
            ++left_it;
            ++current_insertion_point;
        }
    }
}

void sort::mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end || begin + 1 == end)  {
        return;
    }

    auto middle = begin + (end - begin) / 2;
    mergeSort(begin, middle);
    mergeSort(middle, end);
    merge(begin, middle, end);
}