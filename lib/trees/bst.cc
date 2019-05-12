#include <lib-algo-ds/bst.h>
#include <algorithm>

BSTree::BSTree() :
    _root{nullptr} {}

BSTree::~BSTree() {
    delete _root;
}

BSTree::Node const* BSTree::root() {
    return _root;
}

namespace {
BSTree::Node* put(BSTree::Node* root, int key, std::string value) {
    if (root == nullptr) {
        return new BSTree::Node(key, value);
    }

    if (key < root->key) {
        root->left = put(root->left, key, value);
    } else if (key > root->key) {
        root->right = put(root->right, key, value);
    } else {
        root->value = value;
    }
    return root;
}

std::string get(BSTree::Node* root, int key) {
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

int height(BSTree::Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return std::max(height(root->left), height(root->right)) + 1;
}


BSTree::Node* minNode(BSTree::Node* root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    } else {
        return minNode(root->left);
    }

}

BSTree::Node* deleteNode(BSTree::Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else  if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->right == nullptr) {
            auto tmp = root->left;
            root->left = nullptr; // so that deleting the root doesn't delete the left child (check dtor of node)
            delete root;
            return tmp;
        } else if (root->left == nullptr) {
            auto tmp = root->right;
            root->right = nullptr;
            delete root;
            return tmp;
        }
        // Both children exist
        auto inorder_successor = minNode(root->right);
        root->key =  inorder_successor->key;
        root->value = inorder_successor->value;
        root->right = deleteNode(root->right, inorder_successor->key);
    }
    return root;
}

}

void BSTree::put(int key, std::string value) {
    _root = ::put(_root, key, value);
}

std::string BSTree::get(int key) {
    return ::get(_root, key);
}

int BSTree::height() {
    return ::height(_root);
}

void BSTree::deleteNode(int key)  {
    _root = ::deleteNode(_root, key);
}
