/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

*/

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += (s[i] - 'A' + 1) * pow(26, s.size() - i - 1);
        }
        return res;
    }
};