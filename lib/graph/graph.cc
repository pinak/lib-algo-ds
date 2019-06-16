#include <lib-algo-ds/graph/graph.h>

using namespace graph;
using namespace std;

Graph::Graph(int vertices) 
: _adjacentEdges(vertices)
{}

void Graph::addEdge(Edge const& edge) {
    // TODO: don't store 3 copies of the edge
    _edges.emplace_back(edge);
    auto v = edge.either();
    auto w = edge.other(v);

    _adjacentEdges.at(v).emplace_back(edge);
    _adjacentEdges.at(w).emplace_back(edge);
}

vector<Edge> Graph::adjacent(int vertex) const {
    return _adjacentEdges.at(vertex);
}

vector<Edge> Graph::edges() const {
    return _edges;
}