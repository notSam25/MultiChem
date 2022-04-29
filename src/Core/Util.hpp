#pragma once
#include "PeriodicTable.hpp"
#include <nlohmann/json.hpp>

std::string periodicTable(reinterpret_cast<char *>(periodic_table));
nlohmann::json elementData = nlohmann::json::parse(periodicTable)["elements"];

namespace mc::util {
template <typename InputType> inline bool IsUppercase(InputType Input) {
  if (std::toupper(Input) == Input)
    return true;

  return false;
}

inline double GetMolarMass(const std::string &EquationInput) {
  double TotalMolarMass = 0.0f;
  double LastMolarMass = 0.0f;
  for (long long int i = 0; i < EquationInput.size(); i++) {
    char curChar = EquationInput[i];
    char nextChar = EquationInput[i + 1];
    std::string CurElement = "";
    if (curChar != 0 && std::isalpha(curChar)) { // Is alphanumeric

      if (mc::util::IsUppercase(curChar)) {
        CurElement += curChar;
        if (!mc::util::IsUppercase(nextChar))
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
      TotalMolarMass = TotalMolarMass - LastMolarMass +
                       (LastMolarMass * (static_cast<int>(curChar) -
                                         48)); // 48 is the ASCII value of 0.
    }
  }
  return TotalMolarMass;
}

inline int GetSubscript(const std::string &EquationInput) {
  int TotalInputCount = 0;
  for (long long int i = 0; i < EquationInput.size(); i++) {
    char curChar = EquationInput[i];
    char nextChar = EquationInput[i + 1];
    std::string CurElement = "";
    if (curChar != 0 && std::isalpha(curChar)) { // Is alphanumeric

      if (mc::util::IsUppercase(curChar)) {
        CurElement += curChar;
        if (!mc::util::IsUppercase(nextChar))
          CurElement += nextChar;

        for (int j = 0; j < elementData.size(); j++) {
          if (elementData[j]["symbol"] == CurElement) {
            TotalInputCount++;
            break;
          }
        }
      }
    } else if (std::isdigit(curChar))
      TotalInputCount =
          (1 * (static_cast<int>(curChar) - 48)); // 48 is the ASCII value of 0.
  }
  return TotalInputCount;
}
} // namespace mc::util