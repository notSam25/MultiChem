#include <string>

#include "Core/MoleConversion.hpp"

namespace mc::MoleConversion {
void Convert(nlohmann::json input) {
  std::string toConvert = input.value("Output", "");
  if (toConvert == "moles") {
    if (input.value("Mass", "") == "")
      throw std::runtime_error("MoleConversion.Mass error");

    if (input.value("Equation", "") == "")
      throw std::runtime_error("MoleConversion.Equation error");

    std::string EquationStr = input.value("Equation", "");
    double SampleMass = std::atof(input.value("Mass", "0.0").c_str());
    double MolarMass = mc::Util::GetMolarMass(EquationStr);

    std::cout << "Total MolarMass of [ " << EquationStr << " , " << MolarMass
              << " ]" << std::endl;
    double GMole = SampleMass / MolarMass;
    std::cout << "SampleMass -> " << SampleMass << std::endl;
    std::cout << "MolarMass  -> " << MolarMass << std::endl;
    std::cout << "GMole      -> " << GMole << std::endl;
  } else if (toConvert == "mass") {
    if (input.value("Moles", "") == "") {
      std::runtime_error("MoleConversion.Moles error");
    }

    if (input.value("Equation", "") == "") {
      std::runtime_error("MoleConversion.Equation error");
    }

    std::string EquationStr = input.value("Equation", "");
    double SampleMoles = std::atof(input.value("Moles", "0.0").c_str());
    double MolarMass = mc::Util::GetMolarMass(EquationStr);

    std::cout << "Total MolarMass of [ " << EquationStr << " , " << MolarMass
              << " ]" << std::endl;
    double SampleMass = SampleMoles * MolarMass;
    std::cout << "SampleMoles     -> " << SampleMoles << std::endl;
    std::cout << "MolarMass       -> " << MolarMass << std::endl;
    std::cout << "SampleMass      -> " << SampleMass << std::endl;
  }
}
} // namespace mc::MoleConversion
