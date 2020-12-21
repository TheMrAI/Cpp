#include <benchmark/benchmark.h>
#include "counting_sort.h"

#include <algorithm>
#include <iterator>
#include <vector>

using namespace mrai;

#include "data_generators.hpp"

static void counting_sort(benchmark::State& state)
{
  auto input = generate_positive_sequence(state.range(0));
  for (auto _ : state)
  {
    counting_sort(input, state.range(0));
  }
}
BENCHMARK(counting_sort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

BENCHMARK_MAIN();