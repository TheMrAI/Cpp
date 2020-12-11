#ifndef ALGORITHMS_BENCHMARK_DATA_GENERATORS
#define ALGORITHMS_BENCHMARK_DATA_GENERATORS

#include <algorithm>
#include <vector>
#include <random>

namespace mrai
{

auto generate_random_sequence(unsigned elements_to_generate) -> std::vector<int>
{
  std::random_device random_device{};
  std::mt19937 generator{random_device()};

  auto range_end = std::floor(elements_to_generate / 2);
  std::uniform_int_distribution<> distribution(-range_end, range_end);

  auto sequence = std::vector<int>{};
  for(unsigned generated = 0; generated < elements_to_generate; ++generated)
  {
    sequence.emplace_back(distribution(generator));
  }

  return sequence;
}

auto generate_incrementing_sequence(unsigned elements_to_generate) -> std::vector<int>
{
  auto sequence = generate_random_sequence(elements_to_generate);
  std::sort(sequence.begin(), sequence.end());

  return sequence;
}

auto generate_random_target(unsigned elements_to_generate) -> int
{
  std::random_device random_device{};
  std::mt19937 generator{random_device()};

  auto range_end = std::floor(elements_to_generate / 2);
  std::uniform_int_distribution<> distribution(-range_end, range_end);

  return distribution(generator);
}

} // namespace mrai

#endif // ALGORITHMS_BENCHMARK_DATA_GENERATORS