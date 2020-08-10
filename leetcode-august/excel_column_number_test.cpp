#include <catch2/catch.hpp>
#include "excel_column_number.hpp"

#include <vector>

TEST_CASE("Excel column") {
    struct TestCaseEntry {
        std::string test_string{};
        int result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {"A", 1},
        {"B", 2},
        {"Z", 26},
        {"AA",27},
        {"AB", 28} 

    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto result = s.titleToNumber(test_case.test_string);
        REQUIRE(result == test_case.result);
    }
}