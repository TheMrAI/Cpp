#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <optional>

auto possible( int target_length, int target_cost ) -> bool
{
  auto minimum = target_length - 1;
  auto maximum = ( target_length * ( target_length + 1 ) ) / 2 - 1;
  return ( target_cost >= minimum ) && ( target_cost <= maximum );
}

auto choose_cost( int target_length, int target_cost )
{
  // target_length - 1 as the minimum cost for the range, and -1 because we are already using up at least one
  auto cost_that_needs_to_remain = target_length - 2;
  return std::min( target_length, target_cost - cost_that_needs_to_remain );
}

auto reversort_engineering( int target_length, int target_cost ) -> std::optional<std::deque<unsigned>>
{
  if ( target_length == 1 )
  {
    return std::make_optional( std::deque<unsigned>{ 1 } );
  }
  if ( !possible( target_length, target_cost ) )
  {
    return std::nullopt;
  }
  auto chosen_cost = choose_cost( target_length, target_cost );
  auto engineered = reversort_engineering( target_length - 1, target_cost - chosen_cost );
  if ( !engineered )
  {
    return std::nullopt;
  }
  auto& engineered_sequence = engineered.value();

  std::transform( engineered_sequence.begin(), engineered_sequence.end(), engineered_sequence.begin(),
                  []( unsigned value ) {
                    return value + 1;
                  } );
  engineered_sequence.push_front( 1 );
  std::reverse( engineered_sequence.begin(), std::next( engineered_sequence.begin(), chosen_cost ) );
  return engineered;
}

auto main() -> int
{
  auto test_count = 0U;
  std::cin >> test_count;

  for ( auto i = 1U; i <= test_count; ++i )
  {
    auto target_length = static_cast<size_t>( 0 );
    std::cin >> target_length;
    auto target_cost = 0U;
    std::cin >> target_cost;

    std::cout << "Case #" << i << ": ";
    try
    {
      auto result = reversort_engineering( target_length, target_cost );
      if ( result )
      {
        auto& data = result.value();
        for ( unsigned j = 0; j < data.size(); ++j )
        {
          if ( j > 0 )
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
    } catch ( std::exception const& exception )
    {
      std::cerr << exception.what() << '\n';
    }
    std::cout << "\n";
  }
  return 0;
}