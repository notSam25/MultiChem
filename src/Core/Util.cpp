#include "Core/Util.hpp"

std::string periodicTable(reinterpret_cast<char *>(periodic_table));
nlohmann::json elementData = nlohmann::json::parse(periodicTable)["elements"];

namespace mc::Util {
double GetMolarMass(const std::string &EquationInput) {
  double TotalMolarMass = 0.0f;
  double LastMolarMass = 0.0f;
  for (long long int i = 0; i < EquationInput.size(); i++) {
    char curChar = EquationInput[i];
    char nextChar = EquationInput[i + 1];
    std::string CurElement = "";
    if (curChar != 0 && std::isalpha(curChar)) { // Is alphanumeric

      if (IsUppercase(curChar)) {
        CurElement += curChar;
        if (!IsUppercase(nextChar))
          CurElement += nextChar;

        for (int j = 0; j < elementData.size(); j++) {
          if (elementData[j]["symbol"] == CurElement) {
            TotalMolarMass =
                TotalMolarMass + elementData[j].value("atomic_mass", 0.0);
            LastMolarMass = elementData[j].value("atomic_mass", 0.0);
            break;
          }
        }
      }
    } else if (std::isdigit(curChar)) {
      TotalMolarMass =
          TotalMolarMass - LastMolarMass +
          (LastMolarMass *
           (static_cast<int>(curChar) -
            '0')); // get integer from char by subtracting the 0 char
    }
  }
  return TotalMolarMass;
}
} // namespace mc::Util