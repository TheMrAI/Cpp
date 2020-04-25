#ifndef ALGORITHMS_MERGE_SORT
#define ALGORITHMS_MERGE_SORT

#include <cmath>
#include <iterator>

namespace mrai
{
template <typename Iter, typename OutIter>
auto merge(Iter lhs_begin, Iter lhs_end, Iter rhs_begin, Iter rhs_end,
           OutIter output) -> OutIter
{
  while (lhs_begin < lhs_end || rhs_begin < rhs_end)
  {
    if (lhs_begin != lhs_end && rhs_begin != rhs_end)
    {
      if (*lhs_begin <= *rhs_begin)
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
      if (lhs_begin != lhs_end)
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
auto merge_sort(Iter begin, Iter end, OutIter output) -> void
{
  auto distance = std::distance(begin, end);
  if (distance > 1)
  {
    auto midpoint = std::next(begin, std::floor(distance / 2));

    // ghetto, but no better idea
    // using data_type = typename std::iterator_traits<Iter>::value_type;
    // auto lhs_merge_output = std::vector<data_type>();
    merge_sort(begin, midpoint, output);
    // auto rhs_merge_output = std::vector<data_type>();
    merge_sort(midpoint, end, output);
    merge(begin, midpoint, midpoint, end, output);
  }
}

template <typename Iter>
auto in_place_merge(Iter lhs, Iter rhs, Iter end) -> void
{
  auto writer = lhs;
  ++lhs;
  while (rhs < end)
  {
    if (*lhs < *rhs)
    {
      if (*lhs < *writer)
      {
        std::swap(*writer, *lhs);
        ++lhs;
      }
    }
    else
    {
      if (*rhs < *writer)
      {
        std::swap(*writer, *rhs);
        ++rhs;
      }
    }

    ++writer;
    if (writer == lhs)
    {
      ++lhs;
    }
    if (lhs == rhs)
    {
      ++rhs;
    }
  }
}

template <typename Iter>
auto merge_sort_in_place(Iter begin, Iter end) -> void
{
  auto distance = std::distance(begin, end);
  if (distance > 1)
  {
    auto midpoint = std::next(begin, std::floor(distance / 2));
    merge_sort_in_place(begin, midpoint);
    merge_sort_in_place(midpoint, end);
    in_place_merge(begin, midpoint, end);
  }
}

}  // namespace mrai
#endif  // ALGORITHMS_MERGE_SORT