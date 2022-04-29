cmake_minimum_required(VERSION 3.16)
project(MultiChem)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
    src/entry.cpp

    src/Core/Balancer.cpp
    src/Core/Filesystem.cpp
    src/Core/MoleConversion.cpp
    src/Core/PeriodicTable.cpp
    src/Core/Util.cpp
)

add_executable(mchem ${SOURCE})
target_include_directories(mchem PUBLIC include)
target_compile_features(mchem PUBLIC cxx_std_17)

add_subdirectory(vendor)
target_link_libraries(mchem PUBLIC ghc_filesystem nlohmann_json samHeaders args)