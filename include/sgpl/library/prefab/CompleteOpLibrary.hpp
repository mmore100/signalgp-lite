#pragma once

#include "../../operations/operations.hpp"

#include "../OpLibrary.hpp"

namespace sgpl {

using CompleteOpLibrary = sgpl::OpLibrary<
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
  sgpl::global::RegulatorAdj,
  sgpl::global::RegulatorGet,
  sgpl::global::RegulatorSet,
  sgpl::local::Anchor,
  sgpl::local::JumpIf,
  sgpl::local::JumpIfNot,
  sgpl::local::RegulatorAdj,
  sgpl::local::RegulatorGet,
  sgpl::local::RegulatorSet,
  sgpl::Decrement,
  sgpl::Generate,
  sgpl::Increment,
  sgpl::Negate,
  sgpl::Not,
  sgpl::Terminal<>
>;

} // namespace sgpl
