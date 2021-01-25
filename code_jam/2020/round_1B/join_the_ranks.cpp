#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

auto reorder_the_deck( int R, int S ) -> std::vector<std::pair<int, int>>
{
  auto value_order = std::vector<int>{};
  for ( auto suite = 1; suite <= S; ++suite )
  {
    for ( auto rank = 1; rank <= R; ++rank )
    {
      value_order.emplace_back( rank );
    }
  }

  auto steps = std::vector<std::pair<int, int>>{};

  while ( true )
  {
    /*for ( auto value : value_order )
    {
      std::cout << value << " ";
    }
    std::cout << std::endl;*/
    auto i = 0;
    auto first_target = value_order[i];
    while ( first_target == value_order[i] )
    {
      ++i;
    }
    while ( i < value_order.size() && first_target != value_order[i] )
    {
      ++i;
    }
    if ( i == value_order.size() )
    {
      break;
    }
    if ( i == value_order.size() - 1 )
    {
      i = i - 1;
    }

    auto second_target = value_order[i + 1];
    auto j = i;
    while ( j >= 0 && second_target != value_order[j] )
    {
      --j;
    }

    steps.emplace_back( j + 1, i - j );

    auto new_ordering = std::vector<int>{};
    std::copy( std::next( value_order.cbegin(), j + 1 ), std::next( value_order.cbegin(), i + 1 ),
               std::back_inserter( new_ordering ) );
    std::copy( value_order.cbegin(), std::next( value_order.cbegin(), j + 1 ), std::back_inserter( new_ordering ) );
    std::copy( std::next( value_order.cbegin(), i + 1 ), value_order.cend(), std::back_inserter( new_ordering ) );
    value_order = new_ordering;
  }

  return steps;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto R = 0;
    auto S = 0;
    std::cin >> R >> S;
    auto steps = reorder_the_deck( R, S );
    std::cout << "Case #" << i << ": " << steps.size() << std::endl;
    for ( auto const& step : steps )
    {
      std::cout << step.first << " " << step.second << std::endl;
    }
  }
  return 0;
}