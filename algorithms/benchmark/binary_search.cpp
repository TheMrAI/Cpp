#include <benchmark/benchmark.h>
#include "binary_search.h"

#include <vector>

using namespace mrai;

static void BM_recursive_binary_search(benchmark::State& state) 
{
  auto input = { 1, 2, 3, 5, 14, 56, 111, 567, 784, 967, 1113, 5321, 6775 };
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), 967);
}

BENCHMARK(BM_recursive_binary_search);

BENCHMARK_MAIN();