#include <iostream>
#include <algorithm>
#include <vector>
#include <optional>
#include <numeric>

auto reversort_engineering(size_t target_length, unsigned target_cost) -> std::optional<std::vector<unsigned>>
{
    auto result = std::optional<std::vector<unsigned>>();
    auto sequence = std::vector<unsigned>(target_length, 0);
    std::iota(sequence.begin(), sequence.end(), 1);

    auto remaining_cost = static_cast<int>(target_cost) - (static_cast<int>(target_length) - 1);
    if(remaining_cost < 0)
    {
        return result;
    }
    auto offset = 0;
    auto max_reverse_length = static_cast<int>(target_length);
    
    while(remaining_cost > 0 && max_reverse_length > 0)
    {
        auto reverse_length = std::min(remaining_cost + 1, max_reverse_length);

        auto reverse_until = std::prev(sequence.end(), offset);
        auto reverse_from = std::prev(reverse_until, reverse_length);
        std::reverse(reverse_from, reverse_until);
        //std::cout << remaining_cost << " " << reverse_length << std::endl;

        remaining_cost -= reverse_length - 1;
        ++offset;
        max_reverse_length -= 2;
    }
    
    auto extra_permutation = static_cast<int>(target_length) - 2;
    remaining_cost = extra_permutation - remaining_cost + 1;
    while(remaining_cost > 0)
    {
        std::prev_permutation(sequence.begin(), sequence.end());
        --remaining_cost;
    }

    if(remaining_cost == 0)
    {
        result = sequence;
    }

    return result;    
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;

  for ( int i = 1; i <= test_count; ++i )
  {
    auto target_length = static_cast<size_t>(0);
    std::cin >> target_length;
    auto target_cost = 0U;
    std::cin >> target_cost;

    std::cout << "Case #" << i << ": ";
    auto result = reversort_engineering(target_length, target_cost);
    if(result)
    {
        auto& data = result.value();
        for(int j = 0; j < data.size(); ++j)
        {
            if(j > 0)
            {
                std::cout << " ";
            }
            std::cout << data[j];
        }
    }
    else
    {
        std::cout << "IMPOSSIBLE";
    }
    std::cout << "\n";
  }
  return 0;
}