#pragma once
#include "Util.hpp"
#include <cstring>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace mc::MoleConversion {
void Convert(nlohmann::json input);
} // namespace mc::MoleConversion