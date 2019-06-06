#include <lib-algo-ds/disjointset.h>
#include <numeric>

DisjointSet::DisjointSet(int size) :
    _size(size, 1),
    _parent(size) {
    std::iota(_parent.begin(), _parent.end(), 0);
}

bool DisjointSet::connected(int a, int b) {
    return root(a) == root(b);
}
void DisjointSet::connect(int a, int b) {
    auto root_a = root(a);
    auto root_b = root(b);

    if (_size[root_a] > _size[root_b]) {
        _parent[root_b] = root_a;
        _size[root_a] += _size[root_b];
    } else {
        _parent[root_a] = root_b;
        _size[root_b] += _size[root_a];
    }
}

int DisjointSet::connectedComponentSize(int a) {
    return _size[root(a)];
}

int DisjointSet::root(int a) {
    auto current_node = a;
    auto parent = _parent[a];
    while (parent != current_node) {
        // compress the path to root for current
        _parent[current_node] = _parent[parent];

        current_node = parent;
        parent = _parent[current_node];
    }
    return parent;
}