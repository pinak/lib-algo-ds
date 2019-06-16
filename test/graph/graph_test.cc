#include <catch2/catch.hpp>
#include <lib-algo-ds/graph/graph.h>

using namespace graph;

bool edges_same(Edge const& e1, Edge const& e2) {
    return e1.either() == e2.either() &&
         e1.weight() == e2.weight() &&
         e1.other(e1.either()) == e2.other(e2.either());

}

TEST_CASE("basic test") {
    Graph g(4);
    auto e1 = Edge(0, 3, 0.1);
    auto e2 = Edge(0, 1, 0.4);
    
    g.addEdge(e1);
    g.addEdge(e2);

    auto edges = g.edges();
    REQUIRE(edges.size() == 2);
    REQUIRE(edges_same(e1, edges[0]));
    REQUIRE(edges_same(e2, edges[1]));

    
    auto edges0 = g.adjacent(0);
    REQUIRE(edges0.size() == 2);
    REQUIRE(edges_same(e1, edges0[0]));
    REQUIRE(edges_same(e2, edges0[1]));

    auto edges3 = g.adjacent(3);
    REQUIRE(edges3.size() == 1);
    REQUIRE(edges_same(e1, edges3[0]));

    auto edges1 = g.adjacent(1);
    REQUIRE(edges3.size() == 1);
    REQUIRE(edges_same(e2, edges1[0]));

}