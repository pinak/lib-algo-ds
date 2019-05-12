#pragma once
#include <string>
#include <memory>

class BSTree {

public:
    struct Node {
        Node* left{nullptr};
        Node* right{nullptr};
        int key;
        std::string value;

        Node(int key, std::string value) {
            this->key = key;
            this->value = value;
        }
        ~Node() {
            delete left;
            delete right;
        }
    };
    BSTree();
    ~BSTree();
    Node const* root();
    void put(int key, std::string value);
    std::string get(int key);
    int height();
    void deleteNode(int key);

    Node* _root;
};


