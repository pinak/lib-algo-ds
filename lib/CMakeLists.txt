add_library(
    algo-ds
    STATIC
        sort/bubble.cc
        sort/insertion.cc
        sort/merge.cc
        sort/quick.cc
        sort/selection.cc
        tree/bst.cc
        tree/avl.cc
        disjointset.cc

        graph/edge.cc
        graph/graph.cc
        graph/kruskalmst.cc
)

target_include_directories(
    algo-ds
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include/
)