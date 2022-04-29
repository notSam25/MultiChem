#include <version> // to check for filesystem support (provides macros)

#ifdef __cpp_lib_filesystem
#include <filesystem>
#elif __cpp_lib_experimental_filesystem
#include <experimental/filesystem>
#else
#error "could not find any sort of filesystem support"
#endif
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Core/Filesystem.hpp"

#ifdef __cpp_lib_filesystem
namespace fs = std::filesystem;
#elif __cpp_lib_experimental_filesystem
namespace fs = std::experimental::filesystem;
#endif

namespace mc::Filesystem {
std::string GetFileContents(const char *name) {
  try {
    fs::path path(name);
    std::ifstream ifs(path, std::ios::in | std::ios::binary | std::ios::ate);

    std::ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return std::string(&bytes[0], fileSize).c_str();

  } catch (const std::exception &e) {
    std::runtime_error(e.what());
  }
  return "";
}
} // namespace mc::Filesystem
