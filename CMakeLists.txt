cmake_minimum_required(VERSION 3.0.0)
project(BinarySearchTree VERSION 0.1.0)
message("BinarySearchTree: ${CMAKE_SYSTEM_NAME}")
message("BinarySearchTree: ${CMAKE_BUILD_TYPE}")

# include(CTest)
# enable_testing()

# add source files
file(GLOB_RECURSE SRC_FILES 
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(BinarySearchTree 
  ${SRC_FILES}
  examples/bst_main.cpp
)

# includes
target_include_directories(BinarySearchTree PRIVATE 
  ${CMAKE_SOURCE_DIR}/src/
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
