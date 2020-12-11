#include <benchmark/benchmark.h>
#include "binary_search.h"

#include "data_generators.hpp"

using namespace mrai;

static void BM_recursive_binary_search(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(state.range(0));
  auto target = generate_random_target(state.range(0));
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

BENCHMARK(BM_recursive_binary_search)->RangeMultiplier(10)->Range(10, 10'000'000);

static void BM_sequential_binary_search(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(state.range(0));
  auto target = generate_random_target(state.range(0));
  for (auto _ : state)
    [[maybe_unused]] auto result = sequential_binary_search(input.begin(), input.end(), target);
}

BENCHMARK(BM_sequential_binary_search)->RangeMultiplier(10)->Range(10, 10'000'000);


BENCHMARK_MAIN();