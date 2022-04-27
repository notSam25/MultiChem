project(MultiChem)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/entry.cpp
)

add_executable(Build ${SOURCES})
target_include_directories(Build PUBLIC include)