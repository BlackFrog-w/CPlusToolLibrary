cmake_minimum_required(VERSION 3.0.0)
project(cmake_test VERSION 0.1.0)

include(CTest)
enable_testing()


#参考链接
#https://blog.csdn.net/yangpan011/article/details/122835142


#message：输出信息
# https://zhuanlan.zhihu.com/p/370225245
message(STATUS "CMAKE_CURRENT_SOURCE_DIR is:  " ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_LIST_DIR is:  " ${CMAKE_CURRENT_LIST_DIR})
#message("----------------")
#message("CMAKE_CURRENT_SOURCE_DIR is:  " ${CMAKE_CURRENT_SOURCE_DIR})


#


#set
#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin),是用于定义变量的，EXECUTABLE_OUT_PATH和PROJECT_SOURCE_DIR是CMake自带的预定义变量
#cmake自带的预定义变量有哪些？

#list


#if ... endif()

#aux_source_directory 

#find_package
#https://blog.csdn.net/weixin_39393741/article/details/85070299


#add_subdirectory
# add_subdirectory(src)

#include_directories
#include_directories ([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
#https://www.jianshu.com/p/e7de3de1b0fa
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#打印当前include目录
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs = ${dirs}") #打印一下目录情况


#add_library


#find_library

#target_link_libraries


#file

add_executable(cmake_test main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
