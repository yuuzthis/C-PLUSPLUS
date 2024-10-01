cmake_minimum_required(VERSION 3.10)

project(LinkedListProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(source
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/LinkedList.tpp
)

set(include_dir
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/include
)
add_executable(LinkedListApp ${source})

include_directories(${include_dir})