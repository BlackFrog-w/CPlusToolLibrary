cmake_minimum_required(VERSION 3.0.0)
project(load_so VERSION 0.1.0)

include(CTest)
enable_testing()


#头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


#生成静态库
#add_library(load_so load_so.cpp)


#递归递归，将源文件列表存储到 SOURCE_SRC 中
file(GLOB_RECURSE SOURCE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(ALL_SRCS ${SOURCE_SRC})
message(STATUS "ALL_SRCS is: ------- " ${ALL_SRCS})


#生成动态库
add_library(load_so SHARED ${ALL_SRCS})

#指定输出路径
#set_target_properties(load_so PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
