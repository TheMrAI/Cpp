#include <iostream>
#include <string>
#include <algorithm>

auto copyright_costs(int const CJ, int const JC, std::string const & input) -> int
{
    auto costs = 0;

    auto window = std::string("??");
    window[0] = input[0];

    for(size_t i = 1; i < input.size(); ++i)
    {
        window[1] = input[i];
        if(window[1] == '?')
        {
            window[1] = window[0];
        }

        if(window == "CJ")
        {
            costs += CJ;
        }
        else if(window == "JC")
        {
            costs += JC;
        }

        std::reverse(window.begin(), window.end());
    }

    return costs;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;

  for ( int i = 1; i <= test_count; ++i )
  {
    auto CJ = 0;
    std::cin >> CJ;
    auto JC = 0;
    std::cin >> JC;
    auto input = std::string();
    std::cin >> input;

    std::cout << "Case #" << i << ": " << copyright_costs(CJ, JC, input) << "\n";
  }
  return 0;
}