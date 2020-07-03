#ifndef ALGORITHMS_MERGE_SORT
#define ALGORITHMS_MERGE_SORT

#include <algorithm>
#include <iterator>

namespace mrai
{
template <typename Iter, typename OutIter>
auto merge( Iter lhs_begin, Iter lhs_end, Iter rhs_begin, Iter rhs_end, OutIter output ) -> OutIter
{
  while ( lhs_begin < lhs_end || rhs_begin < rhs_end )
  {
    if ( lhs_begin != lhs_end && rhs_begin != rhs_end )
    {
      if ( *lhs_begin <= *rhs_begin )
      {
        *output++ = *lhs_begin++;
      }
      else
      {
        *output++ = *rhs_begin++;
      }
    }
    else
    {
      if ( lhs_begin != lhs_end )
      {
        *output++ = *lhs_begin++;
      }
      else
      {
        *output++ = *rhs_begin++;
      }
    }
  }
  return output;
}

template <typename Iter, typename OutIter>
auto merge_sort( Iter begin, Iter end, OutIter output ) -> void
{
  auto distance = std::distance( begin, end );
  if ( distance > 1 )
  {
    auto midpoint = std::next( begin, distance / 2 );
    // ghetto, but no better idea
    using data_type = typename std::iterator_traits<Iter>::value_type;
    auto lhs_merge_output = std::vector<data_type>();
    merge_sort( begin, midpoint, std::back_inserter( lhs_merge_output ) );
    auto rhs_merge_output = std::vector<data_type>();
    merge_sort( midpoint, end, std::back_inserter( rhs_merge_output ) );
    merge( lhs_merge_output.begin(), lhs_merge_output.end(), rhs_merge_output.begin(), rhs_merge_output.end(), output );
  }
  else  // one element
  {
    std::copy( begin, end, output );
  }
}

template <typename Iter>
auto in_place_merge( Iter lhs, Iter rhs, Iter end ) -> void
{
  if ( rhs == end )
  {
    return;
  }

  using data_type = typename std::iterator_traits<Iter>::value_type;
  auto buffer = std::vector<data_type>{};
  buffer.reserve( std::distance( lhs, end ) );

  merge( lhs, rhs, rhs, end, std::back_inserter( buffer ) );
  std::copy( buffer.begin(), buffer.end(), lhs );
}

template <typename Iter>
auto merge_sort_in_place( Iter begin, Iter end ) -> void
{
  auto distance = std::distance( begin, end );
  if ( distance > 1 )
  {
    auto midpoint = std::next( begin, distance / 2 );
    merge_sort_in_place( begin, midpoint );
    merge_sort_in_place( midpoint, end );
    in_place_merge( begin, midpoint, end );
  }
}

}  // namespace mrai
#endif  // ALGORITHMS_MERGE_SORT