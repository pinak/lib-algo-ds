#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "detect_capital.hpp"

#include <vector>

TEST_CASE("Detect capital") {
    struct TestCaseEntry {
        std::string case_name{};
        std::string test_string{};
        bool result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {"All caps", "USA", true},
        {"All small", "usa", true},
        {"middle incorrect", "uSa", false},
        {"last incorrect", "USa", false},
        {"single small", "a", true},
        {"single big", "B", true},
    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto& case_name = test_case.case_name;
        auto result = s.detectCapitalUse(test_case.test_string);

        SECTION(case_name) {
            REQUIRE(result == test_case.result);
        }
    }
}