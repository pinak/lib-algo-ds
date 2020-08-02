/*
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.


Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)


Note:

    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.

*/

#include <vector>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet()
    : _table(100002, -1) {
        
    }
    
    void add(int key) {
       auto it = find(key);
        *it = key;
    }
    
    void remove(int key) {
        auto it = find(key);
        *it = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto it = find(key);
        return *it != -1;
    }
private:
    int hash(int a) {
        return a % _table.size();
    }
    
    // Returns iterator to the position of the key in the array if the
    // key doesn't exist returns the first empty slot where the key can fit.
    vector<int>::iterator find(int key) {
        auto key_hash = hash(key);
        auto it = _table.begin() + key_hash;
        while(true) {
            if (it == _table.end()) {
                it = _table.begin();
            }
            if (*it == key || *it == -1) {
                return it;
            }
            ++it;
        }
    }
    
    std::vector<int> _table;

};
