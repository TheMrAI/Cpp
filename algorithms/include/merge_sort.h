#ifndef ALGORITHMS_MERGE_SORT
#define ALGORITHMS_MERGE_SORT

#include <cmath>
#include <iterator>

namespace mrai
{
template <typename Iter>
auto in_place_merge(Iter lhs, Iter rhs, Iter end) -> void
{
  while (rhs < end)
  {
    if (*lhs > *rhs)
    {
      std::swap(*lhs, *rhs);
    }
    ++lhs;
    if (lhs == rhs)
    {
      ++rhs;
    }
  }
}

template <typename Iter>
auto merge_sort(Iter begin, Iter end) -> void
{
  auto distance = std::distance(begin, end);
  if (distance > 1)
  {
    auto midpoint = std::next(begin, std::floor(distance / 2));
    merge_sort(begin, midpoint);
    merge_sort(midpoint, end);
    in_place_merge(begin, midpoint, end);
  }
}

}  // namespace mrai
#endif  // ALGORITHMS_MERGE_SORT