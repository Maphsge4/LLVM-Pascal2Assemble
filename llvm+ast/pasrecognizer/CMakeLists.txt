cmake_minimum_required(VERSION 3.5)

add_definitions(-DFULL_IMPL)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
       PROPERTY EP_UPDATE_DISCONNECTED 1)

set(CMAKE_CXX_STANDARD 14)


set(ANTLR_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/antlr4cpp_generated_src)
set(ANTLR_pasLexer_OUTPUT_DIR ${ANTLR_OUTPUT_DIR}/pasLexer)
set(ANTLR_pasParser_OUTPUT_DIR ${ANTLR_OUTPUT_DIR}/pasParser)

include_directories(${ANTLR_pasLexer_OUTPUT_DIR})
include_directories(${ANTLR_pasParser_OUTPUT_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/antlr4-runtime)

list(APPEND ANTLR_pasLexer_CXX_OUTPUTS
    ${ANTLR_pasLexer_OUTPUT_DIR}/pasLexer.cpp)

list(APPEND ANTLR_pasParser_CXX_OUTPUTS
    ${ANTLR_pasParser_OUTPUT_DIR}/pasParser.cpp
    ${ANTLR_pasParser_OUTPUT_DIR}/pasParserBaseListener.cpp
    ${ANTLR_pasParser_OUTPUT_DIR}/pasParserBaseVisitor.cpp
    ${ANTLR_pasParser_OUTPUT_DIR}/pasParserListener.cpp
    ${ANTLR_pasParser_OUTPUT_DIR}/pasParserVisitor.cpp)

# add generated grammar to pas_recognizer binary target
# 实践得出，这些地方不能随便改成pasrecognizer，会在interpreter的make过程中报错，找不到library！
add_library(pasrecognizer
  src/error_listener.cpp
  src/error_reporter.cpp
  src/syntax_tree.cpp
  src/syntax_tree_builder.cpp
  src/recognizer.cpp
  ${ANTLR_pasLexer_CXX_OUTPUTS}
  ${ANTLR_pasParser_CXX_OUTPUTS})
target_link_libraries(pasrecognizer antlr4-runtime)

include_directories(${rapidjson_include_dirs})
add_executable(pasr_test test/main.cpp)
add_dependencies(pasr_test pasrecognizer)
target_link_libraries(pasr_test pasrecognizer)

install(
  TARGETS pasrecognizer
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(DIRECTORY include/pasrecognizer DESTINATION include)

configure_file(pasrecognizer-config.cmake.in pasrecognizer-config.cmake @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/pasrecognizer-config.cmake DESTINATION cmake)
