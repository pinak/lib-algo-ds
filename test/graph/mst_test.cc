#include <catch2/catch.hpp>
#include <lib-algo-ds/graph/kruskalmst.h>
#include <lib-algo-ds/graph/primmmstlazy.h>

using namespace graph;
using namespace std;

namespace {
    bool edges_same(Edge const& e1, Edge const& e2) {
    return e1.either() == e2.either() &&
    e1.weight() == e2.weight() &&
    e1.other(e1.either()) == e2.other(e2.either());
}
}


TEST_CASE("construct MST") {
    Graph g(8);
    for (auto const& edge : vector<Edge>{
        {0, 7, 0.16},
        {2, 3, 0.17},
        {1, 7, 0.19},
        {0, 2, 0.26},
        {5, 7, 0.28},
        {1, 3, 0.29},
        {1, 5, 0.32},
        {2, 7, 0.34},
        {4, 5, 0.35},
        {1, 2, 0.36},
        {4, 7, 0.37},
        {0, 4, 0.38},
        {6, 2, 0.40},
        {3, 6, 0.52},
        {6, 0, 0.58},
        {6, 4, 0.93}
    }) {
        g.addEdge(edge);
    }

    vector<Edge> mst{
        {0, 7, 0.16},
        {2, 3, 0.17},
        {1, 7, 0.19},
        {0, 2, 0.26},
        {5, 7, 0.28},
        {4, 5, 0.35},
        {6, 2, 0.40},
    };

    SECTION("Kruskal") {
        KruskalMST k_mst(g);
        auto const computed_mst =  k_mst.MST();
        REQUIRE(mst.size() == computed_mst.size());
    }
    SECTION("Primm Lazy") {
        PrimmMSTLazy p_mst(g);
        auto const computed_mst =  p_mst.MST();
        REQUIRE(mst.size() == computed_mst.size());
    }
}