#include <iostream>
#include <vector>

struct dancer
{
  uint64_t value = 0;
  int west_neighbour = -1;
  int east_neighbour = -1;
  int north_neighbour = -1;
  int south_neighbour = -1;
  bool to_eliminate = false;
  bool eliminated = false;
};

auto interest_level( std::vector<std::vector<dancer>>& dance_floor ) -> uint64_t
{
  auto interest_level = static_cast<uint64_t>( 0 );

  auto changed = true;
  while ( changed )
  {
    changed = false;
    // count and mark for elimination
    for ( int i = 0; i < dance_floor.size(); ++i )
    {
      for ( int j = 0; j < dance_floor[0].size(); ++j )
      {
        auto& dancer = dance_floor[i][j];
        if ( dancer.eliminated )
        {
          continue;
        }
        interest_level += dancer.value;
        auto compas_neighbour_sum = static_cast<double>( 0 );
        auto compas_neighbour_count = static_cast<double>( 0 );
        if ( dancer.west_neighbour != -1 )
        {
          compas_neighbour_sum += dance_floor[i][dancer.west_neighbour].value;
          ++compas_neighbour_count;
        }
        if ( dancer.east_neighbour != -1 )
        {
          compas_neighbour_sum += dance_floor[i][dancer.east_neighbour].value;
          ++compas_neighbour_count;
        }
        if ( dancer.north_neighbour != -1 )
        {
          compas_neighbour_sum += dance_floor[dancer.north_neighbour][j].value;
          ++compas_neighbour_count;
        }
        if ( dancer.south_neighbour != -1 )
        {
          compas_neighbour_sum += dance_floor[dancer.south_neighbour][j].value;
          ++compas_neighbour_count;
        }
        if ( compas_neighbour_count > 0 && dancer.value < ( compas_neighbour_sum / compas_neighbour_count ) )
        {
          dancer.to_eliminate = true;
          changed = true;
        }
      }
    }

    // eliminate
    for ( int i = 0; i < dance_floor.size(); ++i )
    {
      for ( int j = 0; j < dance_floor[0].size(); ++j )
      {
        auto& dancer = dance_floor[i][j];
        if ( dancer.to_eliminate )
        {
          dancer.to_eliminate = false;
          dancer.eliminated = true;
          if ( dancer.west_neighbour != -1 )
          {
            dance_floor[i][dancer.west_neighbour].east_neighbour = dancer.east_neighbour;
          }
          if ( dancer.east_neighbour != -1 )
          {
            dance_floor[i][dancer.east_neighbour].west_neighbour = dancer.west_neighbour;
          }
          if ( dancer.north_neighbour != -1 )
          {
            dance_floor[dancer.north_neighbour][j].south_neighbour = dancer.south_neighbour;
          }
          if ( dancer.south_neighbour != -1 )
          {
            dance_floor[dancer.south_neighbour][j].north_neighbour = dancer.north_neighbour;
          }
        }
      }
    }
  }

  return interest_level;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto R = 0;
    auto C = 0;
    std::cin >> R >> C;
    int row = 0;
    auto dance_floor = std::vector<std::vector<dancer>>( R, std::vector<dancer>( C, dancer{} ) );
    while ( row < R )
    {
      int column = 0;
      auto contestant_template = dancer{};
      if ( row > 0 )
      {
        contestant_template.north_neighbour = row - 1;
      }
      if ( row < R - 1 )
      {
        contestant_template.south_neighbour = row + 1;
      }
      while ( column < C )
      {
        auto contestant = contestant_template;
        std::cin >> contestant.value;
        if ( column > 0 )
        {
          contestant.west_neighbour = column - 1;
        }
        if ( column < C - 1 )
        {
          contestant.east_neighbour = column + 1;
        }

        dance_floor[row][column] = contestant;
        ++column;
      }
      ++row;
    }
    std::cout << "Case #" << i << ": " << interest_level( dance_floor ) << std::endl;
  }
  return 0;
}