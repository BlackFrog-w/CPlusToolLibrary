cmake_minimum_required(VERSION 3.0.0)
project(cplus_c VERSION 0.1.0)

include(CTest)
enable_testing()

message(test--------------- ${CMAKE_SOURCE_DIR})
message(test--------------- ${CMAKE_CURRENT_LIST_DIR})

include_directories(
    {CMAKE_SOURCE_DIR}/c_fun/
    ${CMAKE_CURRENT_LIST_DIR}/c_fun/
)

add_executable(cplus_c main.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/c_fun/fun.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
