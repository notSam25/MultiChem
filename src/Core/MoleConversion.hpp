#pragma once
#include "Util.hpp"
#include <nlohmann/json.hpp>
#include <iostream>

namespace mc::MoleConversion {
inline void ConvertMoles(nlohmann::json input) {
  std::string toConvert = input.value("Output", "");
  if (toConvert == "moles") {
    if (input.value("Mass", "") == "") {
      std::runtime_error("MoleConversion.Mass error");
    }

    if (input.value("Equation", "") == "") {
      std::runtime_error("MoleConversion.Equation error");
    }

    std::string EquationStr = input.value("Equation", "");
    std::cout << "Total MolarMass of [ " << EquationStr << " , "
              << mc::util::GetMolarMass(EquationStr) << " ]" << std::endl;
  }
}
} // namespace mc::MoleConversion