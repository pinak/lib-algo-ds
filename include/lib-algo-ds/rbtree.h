#pragma once
#include <string>
#include <memory>

class RBTree {

public:
    struct Node {
        enum class Color {
            RED,
            BLACK
        };

        Node* left{nullptr};
        Node* right{nullptr};
        int key;
        std::string value;
        Color color;

        Node(int key, std::string value, Color color) {
            this->key = key;
            this->value = value;
            this->color = color;
        }
        ~Node() {
            delete left;
            delete right;
        }
    };
    RBTree();
    ~RBTree();
    Node const* root();
    void put(int key, std::string value);
    std::string get(int key);
    int height();
    void deleteNode(int key);

    Node* _root;
};


