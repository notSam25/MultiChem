project(MultiChem)
cmake_minimum_required(VERSION 3.16)

set(SOURCES
    src/entry.cpp
)

add_executable(mchem ${SOURCES})
target_include_directories(mchem PUBLIC include)
target_compile_features(mchem PUBLIC cxx_std_17)