#ifndef ALGORITHMS_QUICK_SORT
#define ALGORITHMS_QUICK_SORT

#include <algorithm>
#include <iterator>

namespace mrai
{
// quicksort_of the left and right
// requires bidirectional iterator
template <typename Iter>
auto quicksort_lr( Iter begin, Iter end ) -> void
{
  if ( std::distance( begin, end ) < 2 )
  {
    return;
  }

  auto pivot = std::prev( end, 1 );
  auto smaller = begin;
  auto larger = begin;

  while ( larger != pivot )
  {
    if ( *larger > *pivot )
    {
      ++larger;
    }
    else
    {
      std::iter_swap( smaller, larger );
      ++smaller;
      ++larger;
    }
  }
  std::iter_swap( smaller, pivot );

  quicksort_lr( begin, smaller );
  quicksort_lr( smaller, end );
}

}  // namespace mrai

#endif  // ALGORITHMS_QUICK_SORT