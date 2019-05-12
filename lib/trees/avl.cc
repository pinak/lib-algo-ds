#include <lib-algo-ds/avl.h>
#include <algorithm>
#include <cassert>
#include <iostream>

AvlTree::AvlTree() :
    _root{nullptr} {}

AvlTree::~AvlTree() {
    delete _root;
}

AvlTree::Node const* AvlTree::root() {
    return _root;
}

namespace {

int height(AvlTree::Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->height;
}

AvlTree::Node* rightRotate(AvlTree::Node* root) {
    assert(root != nullptr && root->left != nullptr);
    auto old_root = root;
    auto new_root = root->left;

    old_root->left = new_root->right;
    new_root->right = old_root;

    // update heights
    old_root->height = std::max(height(old_root->left), height(old_root->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

AvlTree::Node* leftRotate(AvlTree::Node* root) {
    assert(root != nullptr && root->right != nullptr);
    auto old_root = root;
    auto new_root = root->right;

    old_root->right = new_root->left;
    new_root->left = old_root;

    // update heights
    old_root->height = std::max(height(old_root->left), height(old_root->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;    
}

int checkBalance(AvlTree::Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return height(root->left) - height(root->right);
}

AvlTree::Node* put(AvlTree::Node* root, int key, std::string value) {
    if (root == nullptr) {
        auto new_node = new AvlTree::Node(key, value);
        new_node->height = 1;
        return new_node;
    }

    if (key < root->key) {
        root->left = put(root->left, key, value);
    } else if (key > root->key) {
        root->right = put(root->right, key, value);
    } else {
        root->value = value;
    }
    root->height = std::max(height(root->left), height(root->right)) + 1;

    // Figure out if balance factor is voilated
    auto balance_factor = checkBalance(root);
    if (balance_factor > 1 && key < root->left->key) {
        //left left
        return rightRotate(root);
    }
    if (balance_factor < -1 && key > root->right->key) {
        // right right
        return leftRotate(root);
    }
    if (balance_factor > 1 && key > root->left->key) {
        // left right
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance_factor < -1 && key < root->right->key) {
        // right left
        root->right = rightRotate(root->right);
    }
        // if yes then check which case it is and perform rotations

    return root;
}

std::string get(AvlTree::Node* root, int key) {
    if (root == nullptr) {
        return {};
    }

    if (key < root->key) {
        return get(root->left, key);
    } else if (key > root->key) {
        return get(root->right, key);
    } else {
        return root->value;
    }
}


AvlTree::Node* minNode(AvlTree::Node* root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    } else {
        return minNode(root->left);
    }
}

}

void AvlTree::put(int key, std::string value) {
    _root = ::put(_root, key, value);
}

std::string AvlTree::get(int key) {
    return ::get(_root, key);
}

int AvlTree::height() {
    return ::height(_root);
}
