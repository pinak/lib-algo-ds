add_subdirectory(Catch2)

add_executable(
    sort-test
        sort_test.cc
)

target_link_libraries(
    sort-test
        Catch2::Catch2
        algo-ds
)

add_test(sort sort-test)