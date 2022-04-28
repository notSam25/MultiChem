#pragma once
#include <cstring>
#include <nlohmann/json.hpp>
#include <stdexcept>

namespace mc::MoleConversion {
inline void ConvertMoles(nlohmann::json input) {
  const char *toConvert = input.value("Output", "").c_str();
  if (strcmp(toConvert, "moles") == 0) {
      
  } else if (strcmp(toConvert, "mass") == 0) {

  } else if (strcmp(toConvert, "particles") == 0) {

  } else
    std::runtime_error("MoleConversion.Output error");
}
} // namespace mc::MoleConversion