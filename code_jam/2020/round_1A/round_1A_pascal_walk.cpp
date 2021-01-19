#include <iostream>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353#problem

constexpr auto overshoot_offset = 30;

auto pascal_walk( std::ostream& out, int N ) -> std::ostream&
{
  auto first_target = static_cast<unsigned>( std::max( 0, N - overshoot_offset ) );
  auto i = 1;
  auto j = 1;
  auto current_sum = 0;

  while ( first_target > 0 )
  {
    auto consume_power_of_two = static_cast<bool>( first_target & 1U );
    first_target = first_target >> 1U;
    if ( consume_power_of_two )
    {
      current_sum += 1U << static_cast<unsigned>( i - 1 );
      if ( j == 1 )
      {
        while ( j <= i )
        {
          out << i << " " << j << '\n';
          ++j;
        }
        j = i;
      }
      else
      {
        while ( j >= 1 )
        {
          out << i << " " << j << '\n';
          --j;
        }
        j = 1;
      }
    }
    else
    {
      ++current_sum;
      out << i << " " << j << '\n';
    }
    ++i;
    if ( j != 1 )
    {
      ++j;
    }
  }

  N = N - current_sum;
  while ( N > 0 )
  {
    out << i << " " << j << '\n';
    ++i;
    if ( j != 1 )
    {
      ++j;
    }
    --N;
  }
  return out;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto number = 0;
    std::cin >> number;
    std::cout << "Case #" << i << ":\n";
    pascal_walk( std::cout, number ) << std::endl;
  }
  return 0;
}