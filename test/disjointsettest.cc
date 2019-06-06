#include <catch2/catch.hpp>
#include <lib-algo-ds/disjointset.h>

TEST_CASE("test connect 1") {
    DisjointSet ds(10);
    REQUIRE(ds.connectedComponentSize(1) == 1);
    REQUIRE(ds.connectedComponentSize(2) == 1);
    REQUIRE(ds.connected(1,2) == false);
    ds.connect(1, 2);
    REQUIRE(ds.connectedComponentSize(1) == 2);
    REQUIRE(ds.connectedComponentSize(2) == 2);
    REQUIRE(ds.connected(1,2) == true);
}

TEST_CASE("test connect 2") {
    DisjointSet ds(10);
    ds.connect(0, 1);
    ds.connect(1, 2);
    REQUIRE(ds.connected(0, 2));
    REQUIRE(ds.connectedComponentSize(0) == 3);
    REQUIRE(ds.connectedComponentSize(1) == 3);
    REQUIRE(ds.connectedComponentSize(2) == 3);
}