#include <benchmark/benchmark.h>

#include <algorithm>
#include <iterator>
#include <vector>

#include "dynamic_programming.h"
#include "data_generators.hpp"

using namespace mrai;

static void lcs_recursive( benchmark::State& state )
{
  auto word_a = generate_random_string_of_length( state.range( 0 ) );
  auto word_b = generate_random_string_of_length( state.range( 0 ) );
  for ( auto _ : state )
  {
    lcs_recursive( word_a, word_b );
  }
}
BENCHMARK( lcs_recursive )->RangeMultiplier( 10 )->Range( 10, 10 )->Complexity();


static void lcs_memoized_recursive( benchmark::State& state )
{
  auto word_a = generate_random_string_of_length( state.range( 0 ) );
  auto word_b = generate_random_string_of_length( state.range( 0 ) );
  for ( auto _ : state )
  {
    lcs_memoized_recursive( word_a, word_b );
  }
}
BENCHMARK( lcs_memoized_recursive )->RangeMultiplier( 10 )->Range( 10, 1000 )->Complexity();


static void lcs_dp_bottom_up( benchmark::State& state )
{
  auto word_a = generate_random_string_of_length( state.range( 0 ) );
  auto word_b = generate_random_string_of_length( state.range( 0 ) );
  for ( auto _ : state )
  {
    lcs_dp_bottom_up( word_a, word_b );
  }
}
BENCHMARK( lcs_dp_bottom_up )->RangeMultiplier( 10 )->Range( 10, 1000 )->Complexity();

BENCHMARK_MAIN();