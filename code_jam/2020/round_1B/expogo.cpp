#include <cmath>
#include <iostream>
#include <queue>
#include <string>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62#problem

struct road
{
  int x = 0;
  int y = 0;
  int i_th_power = 0;
  std::string current_path;
};

auto is_possibile( int x, int y ) -> bool
{
  return ( std::abs( x ) + std::abs( y ) ) % 2 != 0;
}

// Memory limit exceeded on Test Set 3

auto expogo_dfs( int x, int y ) -> std::string
{
  if ( !is_possibile( x, y ) )
  {
    return "IMPOSSIBLE";
  }
  auto to_check = std::queue<road>{};
  to_check.push( road{ 0, 0, 0, std::string() } );

  auto max_jumps = static_cast<size_t>( std::ceil( std::log2( std::abs( x ) + std::abs( y ) ) ) );

  while ( !to_check.empty() )
  {
    auto checking = to_check.front();
    to_check.pop();

    if ( checking.x == x && checking.y == y )
    {
      return checking.current_path;
    }

    if ( max_jumps >= checking.current_path.size() )
    {
      auto current_power = 1 << checking.i_th_power;  // NOLINT
      auto next_power = checking.i_th_power + 1;

      auto west_x = checking.x - current_power;
      to_check.push( { west_x, checking.y, next_power, checking.current_path + 'W' } );

      auto east_x = checking.x + current_power;
      to_check.push( { east_x, checking.y, next_power, checking.current_path + 'E' } );

      auto south_y = checking.y - current_power;
      to_check.push( { checking.x, south_y, next_power, checking.current_path + 'S' } );

      auto north_y = checking.y + current_power;
      to_check.push( { checking.x, north_y, next_power, checking.current_path + 'N' } );
    }
  }

  return std::string( "IMPOSSIBLE" );
}

auto expogo_rescaler( int x, int y ) -> std::string
{
  auto path = std::string();
  while ( is_possibile( x, y ) && !( x == 0 && y == 0 ) )
  {
    if ( x % 2 != 0 )
    {
      auto x_plus = x + 1;
      if ( x_plus == 0 && y == 0 )
      {
        path += 'W';
        x = x_plus;
        continue;
      }
      auto x_minus = x - 1;
      if ( x_minus == 0 && y == 0 )
      {
        path += 'E';
        x = x_minus;
        continue;
      }

      if ( is_possibile( x_plus / 2, y / 2 ) )  // is the rescalled possible?
      {
        x = x_plus;
        path += 'W';
      }
      else
      {
        x = x_minus;
        path += 'E';
      }
    }
    else  // y % 2 != 0
    {
      auto y_plus = y + 1;
      if ( x == 0 && y_plus == 0 )
      {
        path += 'S';
        y = y_plus;
        continue;
      }
      auto y_minus = y - 1;
      if ( x == 0 && y_minus == 0 )
      {
        path += 'N';
        y = y_minus;
        continue;
      }
      if ( is_possibile( x / 2, y_plus / 2 ) )
      {
        y = y_plus;
        path += 'S';
      }
      else
      {
        y = y_minus;
        path += 'N';
      }
    }
    x /= 2;
    y /= 2;
  }

  if ( x == 0 && y == 0 )
  {
    return path;
  }
  return std::string( "IMPOSSIBLE" );
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto x = 0;
    auto y = 0;
    std::cin >> x >> y;
    std::cout << "Case #" << i << ": " << expogo_rescaler( x, y ) << std::endl;
  }
  return 0;
}