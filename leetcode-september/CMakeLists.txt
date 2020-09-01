
add_executable(
    leetcode_september_test
        largest_time_digits.cpp
)


target_link_libraries(
    leetcode_september_test
        Catch2::Catch2
)

add_test(leetcode_september leetcode_september_test)
