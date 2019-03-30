#define CATCH_CONFIG_MAIN

#include <lib-algo-ds/sort.h>
#include <catch2/catch.hpp>
#include <algorithm>
#include <vector>

std::vector<int> sort_using_std_sort(std::vector<int> const& v) {
    auto result = v;
    std::sort(result.begin(), result.end());
    return result;
}

TEST_CASE("Sort tests") {
    using namespace std;
    using TestCaseEntry = pair<string, vector<int>>;
    auto cases = vector<TestCaseEntry>{
        {"repeated values", {4, 4, 4, 4, 4}},
        {"negative values", {4, 41, 5, -325, 253, -9, 6, 1}},
        {"unique values", {4, 41, 5, 325, 253, 9, 6, 1}},
        {"already sorted", {1, 2, 3, 4, 5, 6, 7}},
        {"even number of values", {3, 5, 6, 1, 4, 9}},
        {"odd number of values", {3, 5, 6, 1, 4}},
        {"empty vector", {}}
    };
    for (auto& test_case : cases) {
        auto& case_name = test_case.first;
        auto& unsorted_data = test_case.second;
        auto sorted = sort_using_std_sort(unsorted_data);

        SECTION("Bubble Sort with " + case_name) {
            sort::bubbleSort(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }

        SECTION("Insertion sort with " + case_name) {
            sort::insertionSort(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }

        SECTION("Selection sort with " + case_name) {
            sort::selectionSort(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }

        SECTION("Merge sort with " + case_name) {
            sort::mergeSort(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }

        SECTION("Quick sort Lomuto partition with " + case_name) {
            sort::quickSortLomuto(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }

        SECTION("Quick sort partition with " + case_name) {
            sort::quickSort(unsorted_data.begin(), unsorted_data.end());
            REQUIRE(unsorted_data == sorted);
        }
    }
}