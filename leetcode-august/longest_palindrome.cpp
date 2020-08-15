#include <unordered_map>
#include <string>

namespace {
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char_freq;
        for (auto const c : s) {
            if (char_freq.find(c) == char_freq.end()) {
                char_freq[c] = 1;
            } else {
                char_freq[c]++;
            }
        }
        int res = 0;
        bool extra_char{false};
        for (auto const& entry : char_freq) {
            if (entry.second % 2 == 0) {
                res += entry.second;
            } else {
                res += entry.second - 1;
                extra_char = true;
            }
        }
        
        return extra_char ? res + 1 : res;
    }
};
}
/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("longest palindrome") {
    struct TestCaseEntry {
        std::string test_string{};
        int result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {"abccccdd", 7},
    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto result = s.longestPalindrome(test_case.test_string);
        REQUIRE(result == test_case.result);
    }
}