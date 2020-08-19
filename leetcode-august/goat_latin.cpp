#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<char> const _vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string const _suffix ="ma";
    
    vector<string> tokenize(string const& s) {
        stringstream stream{s};
        string current_word;
        vector<string> res;
        while (stream >> current_word) {
            res.push_back(current_word);
        }
        return res;
    }
public:
    string toGoatLatin(string S) {
        stringstream res;
        
        size_t i = 1;
        auto const& tokens = tokenize(S);
        for (auto const& word : tokens) {
            auto goat_latin_word = word;
            if (_vowels.find(word.front()) != _vowels.end()) {
                goat_latin_word += _suffix;
            } else {
                goat_latin_word.erase(goat_latin_word.begin());
                goat_latin_word += word.front();
                goat_latin_word += _suffix;
            }
            
            goat_latin_word += string(i, 'a');
            res << goat_latin_word;
            
            if (i != tokens.size()) {
                res << " ";
            }
            
            ++i;
        }
        return res.str();
    }
};

/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.
     
    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".
     
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.

Return the final sentence representing the conversion from S to Goat Latin. 
*/

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("goat latin") {
    struct TestCaseEntry {
        std::string test_string{};
        std::string result{};
    };
    

    auto cases = std::vector<TestCaseEntry>{
        {"I speak Goat Latin", "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"},
        {"The quick brown fox jumped over the lazy dog", "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"},
    };
    
    Solution s;
    for (auto& test_case : cases) {
        auto result = s.toGoatLatin(test_case.test_string);
        REQUIRE(result == test_case.result);
    }
}