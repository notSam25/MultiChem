#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace mc::BalanceEquation {
void BalanceEquation(nlohmann::json Balance) {
  if (Balance.value("Reactants", "") == "")
    std::runtime_error("BalanceEquation.Reactants error");

  if (Balance.value("Products", "") == "")
    std::runtime_error("BalanceEquation.Products error");

  if (Balance.value("ReactionType", "") == "")
    std::runtime_error("BalanceEquation.ReactionType error");
}
} // namespace mc::BalanceEquation