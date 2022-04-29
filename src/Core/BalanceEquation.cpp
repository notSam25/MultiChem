#include "Core/BalanceEquation.hpp"
#include <stdexcept>
namespace mc::BalanceEquation {

void BalanceEquation(nlohmann::json input) {
  if (input.value("Reactants", "") == "")
    throw std::runtime_error("BalanceEquation.Reactants error");

  if (input.value("Products", "") == "")
    throw std::runtime_error("BalanceEquation.Products error");

  if (input.value("ReactionType", "") == "")
    throw std::runtime_error("BalanceEquation.ReactionType error");

  // Reaction types: synthesis. decomposition, combustion, double-replacement,
  // single-replacement
  if (input.value("ReactionType", "") == "synthesis") {
  }
  if (input.value("ReactionType", "") == "decomposition") {
  }
  if (input.value("ReactionType", "") == "combustion") {
  }
  if (input.value("ReactionType", "") == "double-replacement") {
  }
  if (input.value("ReactionType", "") == "single-replacement") {
  } else
    throw std::runtime_error("BalanceEquation.ReactionType error");
}
} // namespace mc::BalanceEquation