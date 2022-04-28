#pragma once
#include "PeriodicTable.hpp"
#include <cctype>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <string>

namespace mc::MoleConversion {
inline void ConvertMoles(nlohmann::json input) {
  printf("made it 1\n");
  std::string toConvert = input.value("Output", "");
  if (toConvert == "moles") {
    printf("Made it 2\n");
    // Has particles
    if (input.value("Mass", "") == "") {
      std::runtime_error("MoleConversion.Mass error");
    }

    if (input.value("Equation", "") == "") {
      std::runtime_error("MoleConversion.Equation error");
    }

    std::string periodicTable(reinterpret_cast<char *>(periodic_table));
    nlohmann::json elementData =
        nlohmann::json::parse(periodicTable)["elements"];
    std::string EquationStr = input.value("Equation", "");

    char buf[2] = {0x0, 0x0};
    for(const auto& ch : EquationStr) {
      if(std::isalpha(ch)) {

      }
    }
  } else if (toConvert == "moles") {

  } else
    std::runtime_error("MoleConversion.Output error");
}
} // namespace mc::MoleConversion