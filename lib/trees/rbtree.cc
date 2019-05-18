#include <lib-algo-ds/rbtree.h>

using Node = RBTree::Node;

RBTree::RBTree()
    : _root{nullptr}{}

Node const* RBTree::root() {
    return _root;
}