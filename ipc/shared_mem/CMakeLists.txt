cmake_minimum_required(VERSION 3.0.0)
project(shared_mem_server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(shared_mem_server server.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
