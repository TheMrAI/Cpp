#ifndef ALGORIGHTMS_BINARY_SEARCH
#define ALGORIGHTMS_BINARY_SEARCH

#include <vector>

namespace mrai
{
template <class Iter>
auto recursive_binary_search( Iter begin, Iter end, int target ) -> bool
{
  if ( std::distance( begin, end ) <= 1 )
  {
    return begin != end && *begin == target;
  }

  auto middle_element_offset = static_cast<std::size_t>( std::distance( begin, end ) / 2 );
  Iter middle = std::next( begin, middle_element_offset );

  if ( target < *middle )
  {
    return recursive_binary_search( begin, middle, target );
  }
  else  // NOLINT
  {
    return recursive_binary_search( middle, end, target );
  }
}

template <class Iter>
auto sequential_binary_search( Iter begin, Iter end, int target ) -> bool
{
  if ( begin == end )
  {
    return false;
  }

  while ( std::distance( begin, end ) > 1 )
  {
    auto middle_element_offset = static_cast<std::size_t>( std::distance( begin, end ) / 2 );
    Iter middle = std::next( begin, middle_element_offset );
    if ( target < *middle )
    {
      end = middle;
    }
    else
    {
      begin = middle;
    }
  }

  return *begin == target;
}

}  // namespace mrai
#endif  // ALGORIGHTMS_BINARY_SEARCH