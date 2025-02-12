add_subdirectory(antlr4_runtime)

# Just to show header files in the IDE
file(GLOB_RECURSE GQL_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/gql ${CMAKE_CURRENT_SOURCE_DIR}/../../include/gql/*.*)

foreach(i ${GQL_HEADER_FILES})
  get_filename_component(_dir ${i} PATH)
  set(_pregroup "Headers/${_dir}")
  set(_name "../../include/gql/${i}")
  list(APPEND GQL_HEADERS
    ${_name}
  )
  string(REPLACE "/" "\\" _group ${_pregroup})
  source_group(${_group} FILES ${_name})
endforeach()

file(GLOB GQL_PARSER_SOURCES
  "parser.cpp"
  "generated/*.cpp"
)

add_library(gql_parser STATIC
  ${GQL_PARSER_SOURCES}
  ${GQL_HEADERS}
)

target_include_directories(gql_parser
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include/gql/parser/detail
)

target_link_libraries(gql_parser antlr4_static)

add_executable(gql_parser_test
  parse_file_test.cpp
  parser_test.cpp
  parser_unittest.cpp
)

if(0)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_link_options(gql_parser_test PRIVATE -Wl,--gc-sections -Wl,--print-gc-sections)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_options(gql_parser_test PRIVATE /MAP:linker_map.txt)
    target_link_options(gql_parser_test PRIVATE /OPT:REF /VERBOSE)
  endif()
endif()

target_link_libraries(gql_parser_test
  gql_parser
  gql_ast_print
  gql_ast_test_utils
  GTest::gtest_main
  GTest::gmock_main
)

target_include_directories(gql_parser_test
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)
gtest_discover_tests(gql_parser_test)
