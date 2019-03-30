add_library(
    algo-ds
    STATIC
        sort/bubble.cc
        sort/insertion.cc
        sort/merge.cc
        sort/quick.cc
        sort/selection.cc
)

target_include_directories(
    algo-ds
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include/
)