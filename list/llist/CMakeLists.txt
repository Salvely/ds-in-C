cmake_minimum_required(VERSION 3.20)
project(llist)

FILE(GLOB SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

# INCLUDE(CMakeForceCompiler)
# CMAKE_FORCE_C_COMPILER(gcc GNU)
# CMAKE_FORCE_CXX_COMPILER(g++ GNU)
# set(CMAKE_C_COMPILER gcc)

set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_DIRECTORY lib)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(llist_lib STATIC src/llist.c include/llist.h)
target_link_libraries(${PROJECT_NAME} llist_lib)