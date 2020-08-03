#include <catch2/catch.hpp>
#include "valid_palindrome.hpp"

#include <vector>

TEST_CASE("Valid panlindrome") {
    struct TestCaseEntry {
        std::string case_name{};
        std::string test_string{};
        bool result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {"Correct with non alphanumeric chars", "A man, a plan, a canal: Panama", true},
        {"Incorrect without alphanumeric chars", "race a car", false},
    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto& case_name = test_case.case_name;
        auto result = s.isPalindrome(test_case.test_string);

        SECTION(case_name) {
            REQUIRE(result == test_case.result);
        }
    }
}