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
    
  // Reaction types: synthesis. decomposition, combustion, double-replacement,
  // single-replacement
  if (Balance.value("ReactionType", "") == "synthesis") {
  }
  if (Balance.value("ReactionType", "") == "decomposition") {
  }
  if (Balance.value("ReactionType", "") == "combustion") {
  }
  if (Balance.value("ReactionType", "") == "double-replacement") {
  }
  if (Balance.value("ReactionType", "") == "single-replacement") {
  }
}
} // namespace mc::BalanceEquation