#pragma once

#include <vector>

class DisjointSet {
public:
    DisjointSet(int size);

    bool connected(int a, int b);
    void connect(int a, int b);
    int connectedComponentSize(int a);

private:
    int root(int a);

    std::vector<int> _parent;
    std::vector<int> _size;
};