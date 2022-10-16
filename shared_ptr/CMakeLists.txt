cmake_minimum_required(VERSION 3.0.0)
project(shared_ptr VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "-pthread")

include(CTest)
enable_testing()

add_executable(shared_ptr main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
