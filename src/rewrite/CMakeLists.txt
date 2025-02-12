add_library(gql_rewrite STATIC
    simplified_path_pattern.cpp
)

target_link_libraries(gql_rewrite
    gql_ast
)

add_executable(gql_rewrite_test
    simplified_path_pattern_unittest.cpp
)

target_link_libraries(gql_rewrite_test
    gql_ast_print
    gql_ast_test_utils
    gql_parser
    gql_rewrite
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gql_rewrite_test)

