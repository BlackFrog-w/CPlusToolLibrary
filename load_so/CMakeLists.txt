cmake_minimum_required(VERSION 3.0.0)
project(load_so VERSION 0.1.0)

include(CTest)
enable_testing()




#生成静态库
#add_library(load_so load_so.cpp)

#生成动态库
add_library(load_so SHARED load_so.cpp)

#指定输出路径
#set_target_properties(load_so PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
