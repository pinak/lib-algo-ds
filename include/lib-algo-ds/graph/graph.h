#pragma once

#include "edge.h"
#include <vector>

namespace graph {
class Graph {
public:
    Graph(int vertices);
    void addEdge(Edge const& edge);
    std::vector<Edge> adjacent(int v) const;
    std::vector<Edge> edges() const;

private:
    std::vector<Edge> _edges;
    std::vector<std::vector<Edge>> _adjacentEdges;
};
}