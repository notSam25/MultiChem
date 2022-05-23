cmake_minimum_required(VERSION 3.16)
project(MultiChem)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
    src/entry.cpp

    src/Core/BalanceEquation.cpp
    src/Core/Filesystem.cpp
    src/Core/MoleConversion.cpp
    src/Core/PeriodicTable.cpp
    src/Core/Util.cpp
)

add_executable(mchem ${SOURCE})
target_include_directories(mchem PUBLIC include)
target_compile_features(mchem PUBLIC cxx_std_17)

# Standard filesystem library needs additional linking options on older compilers
# https://en.cppreference.com/w/cpp/filesystem#Notes
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.1")
    target_link_libraries(mchem stdc++fs)
  else()
    target_link_libraries(mchem)
  endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9.0")
    target_link_libraries(mchem c++fs)
  else()
    target_link_libraries(mchem)
  endif()
else()
  target_link_libraries(mchem)
endif()

add_subdirectory(vendor)
target_link_libraries(mchem PUBLIC nlohmann_json samHeaders args)