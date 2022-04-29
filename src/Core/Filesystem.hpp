#pragma once
#include <ghc/filesystem.hpp>
namespace fs = ghc::filesystem;

namespace mc::filesystem {
std::string getFileContents(const fs::path &name) {
  try {
    fs::ifstream ifs(name, std::ios::in | std::ios::binary | std::ios::ate);

    fs::ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(&bytes[0], fileSize);

    return std::string(&bytes[0], fileSize);

  } catch (const std::exception &e) {
    std::runtime_error(e.what());
  }
  return "";
}
} // namespace mc::filesystem