#include <iostream>
#include <vector>
#include <algorithm>

template<typename Iter>
auto reverse_sort(Iter begin, Iter end) -> unsigned
{
    auto cost = 0U;
    while(begin != std::prev(end, 1))
    {
        auto minimum = std::min_element(begin, end);
        cost += std::distance(begin, minimum) + 1;
        std::reverse(begin, std::next(minimum));
        ++begin;
    }
    return cost;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;

  for ( int i = 1; i <= test_count; ++i )
  {
    auto length = 0;
    std::cin >> length;

    auto input_list = std::vector<int>{};
    while (length > 0)
    {
        auto number = 0;
        std::cin >> number;
        input_list.push_back(number);
        --length;
    }
    std::cout << "Case #" << i << ": " << reverse_sort(input_list.begin(), input_list.end()) << "\n";
  }
  return 0;
}