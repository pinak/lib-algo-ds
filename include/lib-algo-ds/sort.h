#pragma once

#include <vector>

namespace sort {
    void bubbleSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void insertionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void selectionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void quickSortLomuto(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void quickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

}