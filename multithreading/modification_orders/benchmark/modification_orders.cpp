#include <benchmark/benchmark.h>
#include "no_total_modification_order.hpp"
#include "total_modification_order.hpp"

using namespace mrai;

static void no_total_modification_order( benchmark::State& state )
{
  for ( auto _ : state )
  {
    ntmo::experiment(state.range( 0 ));
  }
}

BENCHMARK( no_total_modification_order )->RangeMultiplier( 10 )->Range( 10, 10'000'000 )->Complexity();

static void total_modification_order( benchmark::State& state )
{
  for ( auto _ : state )
  {
    tmo::experiment(state.range( 0 ));
  }
}

BENCHMARK( total_modification_order )->RangeMultiplier( 10 )->Range( 10, 10'000'000 )->Complexity();

BENCHMARK_MAIN();