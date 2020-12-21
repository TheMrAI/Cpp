#ifndef ALGORITHMS_BENCHMARK_DATA_GENERATORS
#define ALGORITHMS_BENCHMARK_DATA_GENERATORS

#include <algorithm>
#include <random>
#include <vector>

namespace mrai
{
auto generate_positive_sequence( unsigned elements_to_generate ) -> std::vector<unsigned>
{
  std::random_device random_device{};
  std::mt19937 generator{ random_device() };
  // check range
  std::uniform_int_distribution<> distribution( 0, --elements_to_generate );

  auto sequence = std::vector<unsigned>{};
  for ( unsigned generated = 0; generated < elements_to_generate; ++generated )
  {
    sequence.emplace_back( distribution( generator ) );
  }

  return sequence;
}

auto generate_random_positive_target( unsigned elements_to_generate ) -> unsigned
{
  std::random_device random_device{};
  std::mt19937 generator{ random_device() };

  std::uniform_int_distribution<> distribution( 0, --elements_to_generate );

  return distribution( generator );
}

auto generate_random_sequence( unsigned elements_to_generate ) -> std::vector<int>
{
  std::random_device random_device{};
  std::mt19937 generator{ random_device() };

  auto range_end = std::floor( elements_to_generate / 2 );
  std::uniform_int_distribution<> distribution( -range_end, range_end );

  auto sequence = std::vector<int>{};
  for ( unsigned generated = 0; generated < elements_to_generate; ++generated )
  {
    sequence.emplace_back( distribution( generator ) );
  }

  return sequence;
}

auto generate_incrementing_sequence( unsigned elements_to_generate ) -> std::vector<int>
{
  auto sequence = generate_random_sequence( elements_to_generate );
  std::sort( sequence.begin(), sequence.end() );

  return sequence;
}

auto generate_random_target( unsigned elements_to_generate ) -> int
{
  std::random_device random_device{};
  std::mt19937 generator{ random_device() };

  auto range_end = std::floor( elements_to_generate / 2 );
  std::uniform_int_distribution<> distribution( -range_end, range_end );

  return distribution( generator );
}

}  // namespace mrai

#endif  // ALGORITHMS_BENCHMARK_DATA_GENERATORS