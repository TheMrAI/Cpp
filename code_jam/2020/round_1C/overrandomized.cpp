#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

constexpr auto test_points = 10'000;
constexpr auto code_table_length = 10;

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto U = 0;
    std::cin >> U;

    auto frequencies = std::unordered_map<char, int>{};
    auto distinct_codes = std::unordered_set<char>{};
    auto element_count = test_points;
    while ( element_count > 0 )
    {
      auto Qi = 0;
      auto code = std::string();
      std::cin >> Qi >> code;
      
      auto entry = frequencies.find( code[0] );
      if ( entry == frequencies.end() )
      {
        entry = frequencies.emplace( code[0], 0 ).first;
      }
      entry->second += 1;

      if ( distinct_codes.size() < code_table_length )
      {
        for ( auto character : code )
        {
          distinct_codes.insert( character );
        }
      }
      --element_count;
    }

    auto benford_distribution = std::vector<std::pair<char, int>>{};
    for ( auto const& frequency : frequencies )
    {
      benford_distribution.emplace_back( frequency );
    }
    std::sort( benford_distribution.begin(), benford_distribution.end(), []( auto const& lhs, auto const& rhs ) {
      return lhs.second > rhs.second;
    } );

    auto code_table = std::string();
    for ( auto code_key : benford_distribution )
    {
      code_table += code_key.first;
      distinct_codes.erase( code_key.first );
    }

    std::cout << "Case #" << i << ": " << *distinct_codes.begin() << code_table << std::endl;
  }
  return 0;
}