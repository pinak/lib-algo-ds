/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way. 
*/

#include <string>

class Solution {
public:
    
    bool is_capital(char c) {
        return c >= 'A' && c <='Z';
    }
    
    bool is_same_case(std::string::iterator begin, std::string::iterator end) {
        if (begin == end) {
            return true;
        }
        auto is_first_capital = is_capital(*begin);
        for (auto it = begin + 1; it != end; ++it) {
            if (is_capital(*it) != is_first_capital) {
                return false;
            }
        }
        return true;
    }
    
    bool detectCapitalUse(std::string word) {
        auto it = word.begin();
        if (!is_capital(*it)) {
            ++it;
            while (it != word.end()) {
                if (is_capital(*it)) {
                    return false;
                }
                ++it;
            }
            return true;
        } else {
            return is_same_case(word.begin() + 1, word.end());
        }
    }
};
