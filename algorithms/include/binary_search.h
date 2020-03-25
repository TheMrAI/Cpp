#ifndef ALGORIGHTMS_BINARY_SEARCH
#define ALGORIGHTMS_BINARY_SEARCH

#include <vector>

namespace mrai
{
auto find(std::vector<int> const& data, int target) -> bool
{
  return binary_search(data.begin(), data.end(), target);
}

template <class Iter>
auto binary_search(Iter begin, Iter end, int target) -> bool
{
  if (begin == end)
  {
    return false;
  }
  auto middle_element_offset =
      static_cast<std::size_t>(std::distance(begin, end) / 2);
  Iter middle = begin;
  std::advance(middle, middle_element_offset);
  if (target == *middle)
  {
    return true;
  }
  else if (target < *middle)
  {
    return binary_search(begin, middle, target);
  }
  else
  {
    return binary_search(middle, end, target);
  }
}

}  // namespace mrai
#endif  // ALGORIGHTMS_BINARY_SEARCH