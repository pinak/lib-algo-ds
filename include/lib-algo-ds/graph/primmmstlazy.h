#pragma once

#include <lib-algo-ds/graph/graph.h>
#include <lib-algo-ds/graph/edge.h>
#include <vector>
#include <queue>

namespace graph {
class PrimmMSTLazy {
public:
    PrimmMSTLazy(Graph const& g);
    std::vector<Edge> MST() const;

private:
    void buildMST(Graph const& g);
    using EdgeMinPQ = std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>;
    void visit(int vertex, Graph const& g, std::vector<bool>& marked, EdgeMinPQ& pq);

    std::vector<Edge> _mst;
};
}