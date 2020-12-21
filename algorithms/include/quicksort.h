#ifndef ALGORITHMS_QUICK_SORT
#define ALGORITHMS_QUICK_SORT

#include <algorithm>
#include <iterator>
#include <random>

#include <iostream>

namespace mrai
{

// quicksort_of the left and right
// requires bidirectional iterator
template <typename Iter>
auto quicksort(Iter begin, Iter end) -> void
{
  auto elements_in_range = std::distance(begin, end);
  if (elements_in_range < 2)
  {
    return;
  }
  
  auto last = std::prev(end, 1);
  auto pivot = std::next(begin, std::distance(begin, end)/2);
  std::iter_swap(pivot, last);
  auto pivot_point = std::partition(begin, last, 
    [last](auto const& element)
    {   
      return element < *last;
    });
  std::iter_swap(pivot_point, last);

  quicksort(begin, pivot_point);
  quicksort(++pivot_point, end);
}

class RandomPivotPicker
{
public:
  template<typename Iter>
  auto operator()(Iter begin, Iter end) -> Iter
  {
    auto elements_in_range = std::distance(begin, end);
    auto distribution = std::uniform_int_distribution<>(0, elements_in_range - 1);
    auto random_step_count = distribution(generator);
    return std::next(begin, random_step_count);
  }
private:
  std::random_device random_device = std::random_device();
  std::mt19937 generator = std::mt19937(random_device());
};

// requires bidirectional iterator
template <typename Iter, typename PickPivot>
auto quicksort_random(Iter begin, Iter end, PickPivot& picker) -> void
{
  auto elements_in_range = std::distance(begin, end);
  if (elements_in_range < 2)
  {
    return;
  }

  auto last = std::prev(end, 1);
  auto pivot = picker(begin, end);
  std::iter_swap(pivot, last);
  auto pivot_point = std::partition(begin, last, 
    [last](auto const& element)
    {   
      return element < *last;
    });
  std::iter_swap(pivot_point, last);

  quicksort_random(begin, pivot_point, picker);
  quicksort_random(++pivot_point, end, picker);
}

}  // namespace mrai

#endif  // ALGORITHMS_QUICK_SORT