/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

 

Constraints:

    s consists only of printable ASCII characters.

*/

#include <string>

using namespace std;

class Solution {
public:
    
    bool isAlphaNumeric(char c) {
        return (c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    
    bool isPalindromeHelper(string::iterator begin, string::iterator end) {
        if (std::distance(begin, end) <= 1) {
            return true;
        }
        auto last = end - 1;
        while (begin != last && !isAlphaNumeric(*begin)) ++begin;
        while (last != begin && !isAlphaNumeric(*last)) --last;
        
        if (begin == last) {
            return true;
        }
        
        return (tolower(*begin) == tolower(*last)) && isPalindromeHelper(begin + 1, last);
    }
    
    bool isPalindrome(string s) {
        return isPalindromeHelper(s.begin(), s.end());
    }
};