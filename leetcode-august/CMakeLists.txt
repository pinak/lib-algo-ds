
add_executable(
    leetcode_test
        detect_capital_test.cpp
        design_hashset_test.cpp
        valid_palindrome_test.cpp
        add_and_search_word_ds_test.cpp
)

target_link_libraries(
    leetcode_test
        Catch2::Catch2
)

add_test(leetcode leetcode_test)