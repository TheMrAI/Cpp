#include <iostream>
#include <utility>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b63

/*
python3 /home/mrai/tinker/Cpp/code_jam/2020/interactive_runner.py python3 /home/mrai/tinker/Cpp/code_jam/2020/round_1B
tests/blinfolded_bullseye/testing_tool.py 1 --
/home/mrai/tinker/Cpp/build/Debug/code_jam/2020/round_1B/blindfolded_bullseye
*/

constexpr auto max_size = 1'000'000'000;
constexpr auto step_size = 1'000'000'000 / 2;

enum class ACTION
{
  CENTER,
  HIT,
  MISS,
  WRONG
};

auto find_circle( std::istream& in, std::ostream& out, std::pair<int, int>& point ) -> ACTION
{
  auto guess_y = step_size;
  while ( guess_y >= -step_size )
  {
    auto guess_x = -step_size;
    while ( guess_x <= step_size )
    {
      out << guess_x << " " << guess_y << std::endl;
      auto judgement = std::string();
      in >> judgement;
      if ( judgement == "CENTER" )
      {
        point = std::make_pair( guess_x, guess_y );
        return ACTION::CENTER;
      }
      else if ( judgement == "HIT" )
      {
        point = std::make_pair( guess_x, guess_y );
        return ACTION::HIT;
      }
      guess_x += step_size;
    }
    guess_y -= step_size;
  }
  return ACTION::MISS;
}

auto find_center_x( std::istream& in, std::ostream& out, std::pair<int, int> const& circle_point, int& center_x )
    -> ACTION
{
  auto [x, y] = circle_point;

  auto left_x = -max_size;
  auto left_hit_x = x;
  auto left_last_x = x;
  while ( left_x < left_hit_x )
  {
    auto middle_x = left_x + ( left_hit_x - left_x ) / 2;

    out << middle_x << " " << y << std::endl;
    auto result = std::string();
    in >> result;

    if ( result == "HIT" )
    {
      left_last_x = middle_x;
      left_hit_x = middle_x - 1;
    }
    else if ( result == "MISS" )
    {
      left_x = middle_x + 1;
    }
    else if ( result == "CENTER" )
    {
      return ACTION::CENTER;
    }
  }

  auto right_x = max_size;
  auto right_hit_x = x;
  auto right_last_x = x;
  while ( right_hit_x < right_x )
  {
    auto middle_x = right_hit_x + ( right_x - right_hit_x ) / 2;
    out << middle_x << " " << y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      right_last_x = middle_x;
      right_hit_x = middle_x + 1;
    }
    else if ( result == "MISS" )
    {
      right_x = middle_x - 1;
    }
    else if ( result == "CENTER" )
    {
      return ACTION::CENTER;
    }
  }

  center_x = left_last_x + ( right_last_x - left_last_x ) / 2;
  return ACTION::HIT;
}

auto find_center_y( std::istream& in, std::ostream& out, std::pair<int, int> const& circle_point, int& center_y )
    -> ACTION
{
  auto [x, y] = circle_point;

  auto bottom_y = -max_size;
  auto bottom_hit_y = y;
  auto bottom_last_y = y;
  while ( bottom_y < bottom_hit_y )
  {
    auto middle_y = bottom_y + ( bottom_hit_y - bottom_y ) / 2;

    out << x << " " << middle_y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      bottom_last_y = middle_y;
      bottom_hit_y = middle_y - 1;
    }
    else if ( result == "MISS" )
    {
      bottom_y = middle_y + 1;
    }
    else if ( result == "CENTER" )
    {
      return ACTION::CENTER;
    }
  }

  auto top_y = max_size;
  auto top_hit_y = y;
  auto top_last_y = y;
  while ( top_hit_y < top_y )
  {
    auto middle_y = top_hit_y + ( top_y - top_hit_y ) / 2;

    out << x << " " << middle_y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      top_last_y = middle_y;
      top_hit_y = middle_y + 1;
    }
    else if ( result == "MISS" )
    {
      top_y = middle_y - 1;
    }
    else if ( result == "CENTER" )
    {
      return ACTION::CENTER;
    }
  }

  center_y = bottom_last_y + ( top_last_y - bottom_last_y ) / 2;
  return ACTION::HIT;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  std::cerr << test_count;
  auto A = 0;
  auto B = 0;
  std::cin >> A >> B;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto circle_point = std::make_pair( 0, 0 );

    auto find_result = find_circle( std::cin, std::cout, circle_point );
    if ( find_result == ACTION::CENTER )
    {
      continue;
    }
    if ( find_result != ACTION::HIT )
    {
      return 0;
    }

    auto center_x = 0;
    auto x_result = find_center_x( std::cin, std::cout, circle_point, center_x );
    if ( x_result == ACTION::CENTER )
    {
      continue;
    }

    auto center_y = 0;
    auto y_result = find_center_y( std::cin, std::cout, { center_x, circle_point.second }, center_y );
    if ( y_result == ACTION::CENTER )
    {
      continue;
    }
    std::cout << center_x << " " << center_y << std::endl;
    auto center_candidate_shot = std::string();
    std::cin >> center_candidate_shot;
    if ( center_candidate_shot == "CENTER" )
    {
      continue;
    }

    // shoot in circles to correct for the calculation errors
    auto offset = 1;
    auto length = 3;
    auto center_found = false;
    while ( !center_found )
    {
      auto y_begin = center_y + offset;
      auto y_last = center_y + offset - length + 1;
      for ( auto y_tipp = y_begin; y_tipp >= y_last && !center_found; --y_tipp )
      {
        auto x_begin = center_x - offset;
        auto x_last = center_x - offset + length - 1;
        for ( auto x_tipp = x_begin; x_tipp <= x_last; ++x_tipp )
        {
          if ( !( x_tipp == x_begin || x_tipp == x_last || y_tipp == y_begin || y_tipp == y_last ) )
          {
            continue;
          }
          std::cout << x_tipp << " " << y_tipp << std::endl;
          auto result = std::string();
          std::cin >> result;
          if ( result == "CENTER" )
          {
            center_found = true;
            break;
          }
        }
      }
      ++offset;
      length += 2;
    }
  }
  return 0;
}