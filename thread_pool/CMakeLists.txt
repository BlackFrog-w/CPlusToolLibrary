cmake_minimum_required(VERSION 3.0.0)
project(thread_pool VERSION 0.1.0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(CTest)
enable_testing()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(thread_pool main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
