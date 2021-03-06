#pragma once

#include <limits>

#include "../../hardware/Core.hpp"
#include "../../program/Instruction.hpp"
#include "../../program/Program.hpp"

namespace sgpl {
namespace global {

struct RegulatorGet {

  template<typename Spec>
  static void run(
    sgpl::Core<Spec>& core,
    const sgpl::Instruction<Spec>& inst,
    const sgpl::Program<Spec>&,
    typename Spec::peripheral_t&
  ) {

    for ( const auto uid : core.GetGlobalJumpTable().MatchRaw(
      inst.tag,
      std::numeric_limits<size_t>::max()
    ) ) {
      // (+) values down regulate
      // (-) values up regulate
      core.registers[ inst.args[0] ]
        = core.GetGlobalJumpTable().ViewRegulator(
        uid
      );
      break; // only process first value
    }

  }

};

} // namespace global
} // namespace sgpl
