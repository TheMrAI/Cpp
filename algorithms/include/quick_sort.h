#ifndef ALGORITHMS_QUICK_SORT
#define ALGORITHMS_QUICK_SORT

#include <algorithm>
#include <iterator>
#include <random>

namespace mrai
{

// quicksort_of the left and right
// requires bidirectional iterator
template <typename Iter>
auto quicksort_lr(Iter begin, Iter end) -> void
{
  if (std::distance(begin, end) < 2)
  {
    return;
  }

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

  quicksort_lr(begin, smaller);
  quicksort_lr(smaller, end);
}

template <typename Iter>
auto quicksort_random(Iter begin, Iter end) ->void
{
  if (std::distance(begin, end) < 2)
  {
    return;
  }

  auto elements_in_range = std::distance(begin, end);
  auto random_device = std::random_device();
  auto generator = std::mt19937(random_device());
  auto distribution = std::uniform_int_distribution<>(0, elements_in_range - 1);
  auto random_step_count = distribution(generator);

  auto pivot = std::next(begin, random_step_count);
  auto last = std::prev(end, 1);
  std::iter_swap(last, pivot);
  pivot = last;
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

  quicksort_random(begin, smaller);
  quicksort_random(smaller, end);
}

}  // namespace mrai

#endif  // ALGORITHMS_QUICK_SORT