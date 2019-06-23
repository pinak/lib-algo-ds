#pragma once

#include <lib-algo-ds/graph/graph.h>
#include <lib-algo-ds/graph/edge.h>
#include <vector>

namespace graph {
class KruskalMST {
public:
    KruskalMST(Graph const& g);
    std::vector<Edge> MST() const;

private:
    void buildMST(Graph const& g);

    std::vector<Edge> _mst;
};
}