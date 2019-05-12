add_subdirectory(Catch2)

add_executable(
    lib-algo-ds-test
        sort_test.cc
        bst_test.cc
        avl_test.cc
)

target_link_libraries(
    lib-algo-ds-test
        Catch2::Catch2
        algo-ds
)

add_test(sort lib-algo-ds-test)