#pragma once

#include <nlohmann/json.hpp>

#include "PeriodicTable.hpp"

extern std::string periodicTable;
extern nlohmann::json elementData;

namespace mc::Util {
template <typename T> inline bool IsUppercase(T in) {
  return std::toupper(in) == in;
}

double GetMolarMass(const std::string &EquationInput);
} // namespace mc::Util
