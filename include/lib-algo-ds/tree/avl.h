#pragma once
#include <string>
#include <memory>

class AvlTree {

public:
    struct Node {
        Node* left{nullptr};
        Node* right{nullptr};
        int key;
        std::string value;
        int height{0};

        Node(int key, std::string value) {
            this->key = key;
            this->value = value;
        }
        ~Node() {
            delete left;
            delete right;
        }
    };
    AvlTree();
    ~AvlTree();
    Node const* root();
    void put(int key, std::string value);
    std::string get(int key);
    int height();
    void deleteNode(int key);

    Node* _root;
};


