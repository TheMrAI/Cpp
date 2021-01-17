#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034#problem

auto pattern_match_result( std::vector<std::string>& patterns ) -> std::string
{
  std::sort( patterns.begin(), patterns.end(), []( auto const& lhs, auto const& rhs ) {
    return lhs.size() > rhs.size();
  } );

  auto valid = true;
  auto pattern_index = static_cast<size_t>( 0 );
  auto preffix = std::string();
  auto suffix = std::string();
  auto internals = std::vector<std::string>();
  while ( valid && pattern_index < patterns.size() )
  {
    // prefix
    auto const& pattern = patterns[pattern_index];
    auto asterix = std::find( pattern.begin(), pattern.end(), '*' );
    auto new_prefix = std::string( pattern.begin(), asterix );
    if ( preffix.size() < new_prefix.size() )
    {
      std::swap( preffix, new_prefix );
    }
    if ( new_prefix != std::string( preffix, 0, new_prefix.size() ) )
    {
      valid = false;
    }

    // middle stuff
    auto next_asterix = std::find( std::next( asterix ), pattern.end(), '*' );
    while ( next_asterix != pattern.end() )
    {
      internals.emplace_back( std::string( std::next( asterix ), next_asterix ) );
      asterix = next_asterix;
      next_asterix = std::find( std::next( asterix ), pattern.end(), '*' );
    }

    // suffix
    if ( asterix != std::prev( pattern.end() ) )
    {
      auto new_suffix = std::string( std::next( asterix ), pattern.end() );
      if ( suffix.size() < new_suffix.size() )
      {
        std::swap( suffix, new_suffix );
      }
      if ( new_suffix != std::string( suffix, suffix.size() - new_suffix.size() ) )
      {
        valid = false;
      }
    }

    ++pattern_index;
  }

  if ( valid )
  {
    auto result = preffix;
    for ( auto const& mid : internals )
    {
      result += mid;
    }
    return result + suffix;
  }
  return "*";
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto number_of_patterns = 0;
    auto patterns = std::vector<std::string>{};

    std::cin >> number_of_patterns;
    while ( number_of_patterns > 0 )
    {
      --number_of_patterns;
      auto pattern = std::string{};
      std::cin >> pattern;

      patterns.push_back( pattern );
    }
    std::cout << "Case #" << i << ": " << pattern_match_result( patterns ) << std::endl;
  }
  return 0;
}