#ifndef ALGORITHMS_QUICK_SORT
#define ALGORITHMS_QUICK_SORT

#include <algorithm>
#include <iterator>
#include <random>

namespace mrai
{

// partition a range between begin and end
// using the element before end as the pivot
// begin != end otherwise the behaviour is undefined
template <typename Iter>
auto partition(Iter begin, Iter end) -> Iter
{
  auto pivot = std::prev(end, 1);
  auto smaller = begin;
  auto larger = begin;

  while (larger != pivot)
  {
    if (*larger <= *pivot)
    {
      std::iter_swap(smaller, larger);
      ++smaller;
    }
    ++larger;
  }
  std::iter_swap(smaller, pivot);

  return smaller;
}

// quicksort_of the left and right
// requires bidirectional iterator
template <typename Iter>
auto quicksort_lr(Iter begin, Iter end) -> void
{
  auto elements_in_range = std::distance(begin, end);
  if (elements_in_range < 2)
  {
    return;
  }

  auto smaller_end = partition(begin, end);

  quicksort_lr(begin, smaller_end);
  quicksort_lr(smaller_end, end);
}

// requires bidirectional iterator
template <typename Iter>
auto quicksort_random(Iter begin, Iter end) ->void
{
  auto elements_in_range = std::distance(begin, end);
  if (elements_in_range < 2)
  {
    return;
  }

  auto random_device = std::random_device();
  auto generator = std::mt19937(random_device());
  auto distribution = std::uniform_int_distribution<>(0, elements_in_range - 1);
  auto random_step_count = distribution(generator);

  auto pivot = std::next(begin, random_step_count);
  auto last = std::prev(end, 1);
  std::iter_swap(last, pivot);

  auto smaller_end = partition(begin, end);

  quicksort_random(begin, smaller_end);
  quicksort_random(smaller_end, end);
}

}  // namespace mrai

#endif  // ALGORITHMS_QUICK_SORT