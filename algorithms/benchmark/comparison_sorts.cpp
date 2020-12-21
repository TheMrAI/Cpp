#include <benchmark/benchmark.h>
#include "heapsort.h"
#include "merge_sort.h"
#include "quicksort.h"

#include <algorithm>
#include <iterator>
#include <vector>

using namespace mrai;

#include "data_generators.hpp"

static void std_sort(benchmark::State& state)
{
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    std::sort(input.begin(), input.end());
  }
}
BENCHMARK(std_sort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

static void merge_sort(benchmark::State& state)
{
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    state.PauseTiming();
    auto output = std::vector<int>{};
    state.ResumeTiming();
    merge_sort(input.begin(), input.end(), std::back_inserter(output));
  }
}
BENCHMARK(merge_sort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

static void heapsort(benchmark::State& state)
{
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    heapsort(input.begin(), input.end());
  }
}
BENCHMARK(heapsort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

static void manual_heapsort(benchmark::State& state)
{
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    manual_heapsort(input.begin(), input.end());
  }
}
BENCHMARK(manual_heapsort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

static void quicksort(benchmark::State& state)
{
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    quicksort(input.begin(), input.end());
  }
}
BENCHMARK(quicksort)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

static void quicksort_random(benchmark::State& state)
{
  RandomPivotPicker picker;
  auto input = generate_random_sequence(state.range(0));
  for (auto _ : state)
  {
    quicksort_random(input.begin(), input.end(), picker);
  }
}
BENCHMARK(quicksort_random)->RangeMultiplier(10)->Range(10, 100'000)->Complexity();

BENCHMARK_MAIN();