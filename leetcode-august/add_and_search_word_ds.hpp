/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <memory>
#include <array>
#include <string>

using namespace std;

class WordDictionary {
    
public:
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> children{};
        bool word_end{false};
    };

    /** Initialize your data structure here. */
    WordDictionary()
    : _root{make_unique<TrieNode>()} {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto current_node = &_root;
        for (auto it = word.begin(); it != word.end(); ++it) {
            auto& next_node = current_node->children[*it - 'a'];
            if (!next_node) {
                next_node = make_unique<TrieNode>();
            }
            
            current_node = next_node.get();
        }
        current_node->word_end = true;
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(&_root, word.begin(), word.end());
    }
private:
    static bool search_helper(TrieNode* root, string::iterator begin, string::iterator end) {
        if (!root) {
            return false;
        }
        
        auto current_node = root;
        
        for (auto it = begin; it != end; ++it) {
            if (*it != '.') {
                current_node = current_node->children[*it - 'a'].get();
                if (!current_node) {
                    return false;
                }
            } else {
                //cout << "dot case" << endl;
                for (auto const& child : current_node->children) {
                    if (search_helper(child.get(), it + 1, end)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return current_node->word_end;
    }

    TrieNode _root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */