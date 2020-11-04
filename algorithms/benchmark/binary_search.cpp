#include <benchmark/benchmark.h>
#include "binary_search.h"

#include <algorithm>
#include <vector>
#include <random>

using namespace mrai;

auto generate_incrementing_sequence(int elements_to_generate) -> std::vector<int>
{
  std::random_device random_device{};
  std::mt19937 generator{random_device()};

  auto range_end = std::floor(elements_to_generate / 2);
  std::uniform_int_distribution<> distribution(-range_end, range_end);

  auto sequence = std::vector<int>{};
  for(int generated = 0; generated < elements_to_generate; ++generated)
  {
    sequence.emplace_back(distribution(generator));
  }

  std::sort(sequence.begin(), sequence.end());

  return sequence;
}

auto generate_random_target(int elements_to_generate) -> int
{
  std::random_device random_device{};
  std::mt19937 generator{random_device()};

  auto range_end = std::floor(elements_to_generate / 2);
  std::uniform_int_distribution<> distribution(-range_end, range_end);

  return distribution(generator);
}

static void BM_recursive_binary_search_10(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(10);
  auto target = generate_random_target(10);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_100(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(100);
  auto target = generate_random_target(100);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_1k(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(1'000);
  auto target = generate_random_target(1'000);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_10k(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(10'000);
  auto target = generate_random_target(10'000);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_100k(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(100'000);
  auto target = generate_random_target(100'000);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_1M(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(1'000'000);
  auto target = generate_random_target(1'000'000);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

static void BM_recursive_binary_search_10M(benchmark::State& state)
{
  auto input = generate_incrementing_sequence(10'000'000);
  auto target = generate_random_target(10'000'000);
  for (auto _ : state)
    [[maybe_unused]] auto result = recursive_binary_search(input.begin(), input.end(), target);
}

BENCHMARK(BM_recursive_binary_search_10);
BENCHMARK(BM_recursive_binary_search_100);
BENCHMARK(BM_recursive_binary_search_1k);
BENCHMARK(BM_recursive_binary_search_10k);
BENCHMARK(BM_recursive_binary_search_100k);
BENCHMARK(BM_recursive_binary_search_1M);
BENCHMARK(BM_recursive_binary_search_10M);

BENCHMARK_MAIN();