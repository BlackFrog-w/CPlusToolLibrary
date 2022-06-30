cmake_minimum_required(VERSION 3.0.0)
project(head_file_declare VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#编译不过去
# add_executable(head_file_declare main.cpp test2.cpp)

#正常编译
add_executable(head_file_declare main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
