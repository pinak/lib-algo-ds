#include <catch2/catch.hpp>
#include <lib-algo-ds/tree/bst.h>

TEST_CASE("bst put get test") {
    constexpr auto v = "some value";
    BSTree bst;
    bst.put(50, v);
    REQUIRE(bst.height() == 1);
    for (int i = 0; i < 10; ++i) {
        bst.put(i, v);
        REQUIRE(bst.height() == i + 2);
    }

    for (int i = 0; i < 10; ++i) {
        REQUIRE(bst.get(i) == v);
    }

    REQUIRE(bst.get(50) == v);
    REQUIRE(bst.root()->key == 50);
    REQUIRE(bst.root()->value == v);
}

TEST_CASE("bst deletion test") {
    constexpr auto v = "some value";
    using namespace std;
    vector<pair<int, string>> const values = {
        {40, v},
        {30, v},
        {50, v},
        {29, v},
        {31, v},
        {28, v},
        {49, v},
        {51, v}
    };
    BSTree bst;
    for (auto const value : values) {
        bst.put(value.first, value.second);
    }
    /* we have a tree that looks like:
                 40
               /     \
              30     50
             /  \    /  \
            29  31  49   51
            /
           28
    */
    SECTION("Delete leaf") {
        int key_of_target_node = 28;
        bst.deleteNode(key_of_target_node);
        for (auto const value : values) {
            if (value.first != key_of_target_node) {
                REQUIRE(bst.get(value.first) == value.second);
            } else {
                REQUIRE(bst.get(value.first) == "");
            }
        }
    }
    SECTION("Delete root with 2 children") {
        int key_of_target_node = 40;
        bst.deleteNode(key_of_target_node);
        for (auto const value : values) {
            if (value.first != key_of_target_node) {
                REQUIRE(bst.get(value.first) == value.second);
            } else {
                REQUIRE(bst.get(value.first) == "");
            }
        }
    }

    SECTION("Delete non root node with 2 children") {
        int key_of_target_node = 50;
        bst.deleteNode(key_of_target_node);
        for (auto const value : values) {
            if (value.first != key_of_target_node) {
                REQUIRE(bst.get(value.first) == value.second);
            } else {
                REQUIRE(bst.get(value.first) == "");
            }
        }
    }

    SECTION("Delete node with one child") {
        int key_of_target_node = 29;
        bst.deleteNode(key_of_target_node);
        for (auto const value : values) {
            if (value.first != key_of_target_node) {
                REQUIRE(bst.get(value.first) == value.second);
            } else {
                REQUIRE(bst.get(value.first) == "");
            }
        }
    }
}