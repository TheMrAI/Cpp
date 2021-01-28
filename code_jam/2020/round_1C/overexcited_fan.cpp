#include <iostream>
#include <limits>
#include <vector>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/0000000000317409

auto catch_pepurr( int x, int y, std::string const& route ) -> std::string
{
  auto route_locations = std::vector<std::pair<int, int>>{};
  route_locations.emplace_back( x, y );
  for ( auto character : route )
  {
    switch ( character )
    {
      case 'N':
        ++y;
        break;
      case 'S':
        --y;
        break;
      case 'W':
        --x;
        break;
      case 'E':
        ++x;
        break;
      default:
        throw std::invalid_argument( std::string( "Unrecognized direction: " ) + character );
    }
    route_locations.emplace_back( x, y );
  }

  auto minimum_distance = std::numeric_limits<int>::max();
  for ( auto i = 1; i < static_cast<int>( route_locations.size() ); ++i )
  {
    auto delta_x = std::abs( route_locations[i].first );
    auto delta_y = std::abs( route_locations[i].second );
    auto hamming_distance = delta_x + delta_y;
    if ( hamming_distance <= i )
    {
      minimum_distance = std::min( minimum_distance, i );
    }
  }

  if ( minimum_distance == std::numeric_limits<int>::max() )
  {
    return "IMPOSSIBLE";
  }
  return std::to_string( minimum_distance );
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto x = 0;
    auto y = 0;
    auto pepurr_route = std::string();
    std::cin >> x >> y;
    std::cin >> pepurr_route;
    std::cout << "Case #" << i << ": " << catch_pepurr( x, y, pepurr_route ) << std::endl;
  }
  return 0;
}