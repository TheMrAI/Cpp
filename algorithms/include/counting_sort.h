#ifndef ALGORITHMS_COUNTING_SORT
#define ALGORITHMS_COUNTING_SORT

#include <limits>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace mrai
{
// specifyining a max_value smaller than the actual maximum value present in
// the input vector causes undefined behaviour
inline auto counting_sort( std::vector<unsigned> const& input, unsigned max_value ) -> std::vector<unsigned>
{
  auto sorted_result = std::vector<unsigned>( input.size() );
  if ( input.empty() )
  {
    return sorted_result;
  }

  if ( max_value == std::numeric_limits<unsigned>::max() )
  {
    throw std::length_error( "max_value has to be smaller than std::numeric_limits<unsigned>::max()!" );
  }
  auto counter = std::vector<unsigned>( max_value + 1, 0 );

  for ( auto const value : input )
  {
    ++counter[value];
  }
  std::partial_sum( counter.begin(), counter.end(), counter.begin() );
  // to keep the stable property we iterate backwards while inserting the results into the
  // output
  for ( size_t i = input.size() - 1;; --i )
  {
    auto value = input[i];
    auto output_index = counter[value] - 1;
    sorted_result[output_index] = value;
    --counter[value];
    // have to break here, otherwise the loop couldn't exist given
    // the unsigned underflow behaviour
    if ( i == 0 )
    {
      break;
    }
  }

  return sorted_result;
}

}  // namespace mrai

#endif  // ALGORITHMS_COUNTING_SORT