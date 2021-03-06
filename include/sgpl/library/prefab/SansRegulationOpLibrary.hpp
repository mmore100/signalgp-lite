#pragma once

#include "../../operations/operations.hpp"

#include "../OpLibrary.hpp"

namespace sgpl {

using SansRegulationOpLibrary = sgpl::OpLibrary<
  sgpl::Fork,
  sgpl::Nop,
  sgpl::Terminate,
  sgpl::Add,
  sgpl::Divide,
  sgpl::Modulo,
  sgpl::Multiply,
  sgpl::Subtract,
  sgpl::Equal,
  sgpl::GreaterThanEqual,
  sgpl::LessThanEqual,
  sgpl::global::Anchor,
  sgpl::global::JumpIf,
  sgpl::global::JumpIfNot,
  sgpl::local::Anchor,
  sgpl::local::JumpIf,
  sgpl::local::JumpIfNot,
  sgpl::Decrement,
  sgpl::Generate,
  sgpl::Increment,
  sgpl::Negate,
  sgpl::Not,
  sgpl::Terminal<>
>;

} // namespace sgpl
