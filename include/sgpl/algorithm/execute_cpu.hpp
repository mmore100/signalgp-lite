#pragma once

#include <tuple>

#include "../config/Spec.hpp"
#include "../hardware/Cpu.hpp"
#include "../program/Program.hpp"
#include "../utility/EmptyType.hpp"

#include "execute_core.hpp"

namespace sgpl {

template<typename Spec>
void execute_cpu(
  const size_t cycles,
  sgpl::Cpu<Spec>& state,
  const sgpl::Program<Spec>& program,
  typename Spec::peripheral_t& peripheral
) {

  for (size_t i{}; i < cycles && state.HasActiveCore(); ++i) {

    auto& core = state.GetActiveCore();
    execute_core<Spec>(core, program, peripheral);
    if ( core.HasTerminated() ) state.KillActiveCore();

    state.TryActivateNextCore();
  }

}

template<typename Spec=sgpl::Spec<>>
void execute_cpu(
  const size_t cycles,
  sgpl::Cpu<Spec>& state,
  const sgpl::Program<Spec>& program
) {

  using peripheral_t = typename Spec::peripheral_t;
  peripheral_t peripheral;

  execute_cpu<Spec>( cycles, state, program, peripheral );

}

} // namespace sgpl
