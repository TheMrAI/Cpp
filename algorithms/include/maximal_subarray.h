#ifndef ALGORITHMS_MAXIMAL_SUBARRAY
#define ALGORITHMS_MAXIMAL_SUBARRAY

#include <algorithm>
#include <vector>

namespace mrai
{

template<typename T>
T kadane(std::vector<T> const& input)
{
  auto maximal_sum{ 0 };
  auto current_sum{ 0 };

  for (const auto element : input)
  {
    current_sum += element;
    if (current_sum < 0)
    {
      current_sum = 0;
    }
    maximal_sum = std::max(maximal_sum, current_sum);
  }

  return maximal_sum;
}

}  // namespace mrai

#endif  // ALGORITHMS_MAXIMAL_SUBARRAY