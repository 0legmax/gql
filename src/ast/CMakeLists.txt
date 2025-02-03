add_library(gql_ast_print STATIC
  output_stream.cpp
)

target_include_directories(gql_ast_print
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
