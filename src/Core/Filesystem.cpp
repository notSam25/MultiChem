#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

#include "Core/Filesystem.hpp"

namespace fs = std::filesystem;

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
}