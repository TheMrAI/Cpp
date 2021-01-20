#include <iostream>
#include <utility>

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b63

// python3 /home/mrai/tinker/Cpp/code_jam/2020/interactive_runner.py python3
// /home/mrai/tinker/Cpp/code_jam/2020/round_1B/tests/blinfolded_bullseye/testing_tool.py 1 --
// /home/mrai/tinker/Cpp/build/Debug/code_jam/2020/round_1B/blindfolded_bullseye

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
  while ( left_x < left_hit_x )
  {
    auto middle_x = left_x + ( left_hit_x - left_x ) / 2;

    out << middle_x << " " << y << std::endl;
    auto result = std::string();
    in >> result;

    if ( result == "HIT" )
    {
      left_hit_x = middle_x;
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
  while ( right_hit_x < right_x )
  {
    auto middle_x = right_hit_x + ( right_x - right_hit_x ) / 2;
    out << middle_x << " " << y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      right_hit_x = middle_x;
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

  center_x = left_hit_x + ( right_hit_x - left_hit_x / 2 );
  return ACTION::HIT;
}

auto find_center_y( std::istream& in, std::ostream& out, std::pair<int, int> const& circle_point, int& center_y )
    -> ACTION
{
  auto [x, y] = circle_point;

  auto bottom_y = -max_size;
  auto bottom_hit_y = y;

  while ( bottom_y < bottom_hit_y )
  {
    auto middle_y = bottom_y + ( bottom_hit_y - bottom_y ) / 2;

    out << x << " " << middle_y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      bottom_hit_y = middle_y;
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
  auto top_last_y = 0;
  while ( top_hit_y < top_y )
  {
    auto middle_y = top_hit_y + ( top_y - top_hit_y ) / 2;

    out << x << " " << middle_y << std::endl;
    auto result = std::string();
    in >> result;
    if ( result == "HIT" )
    {
      top_last_y = top_hit_y;
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

  center_y = bottom_hit_y + ( top_last_y - bottom_hit_y ) / 2;
  return ACTION::HIT;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    auto A = 0;
    auto B = 0;
    std::cin >> A >> B;

    auto circle_point = std::make_pair( 0, 0 );
    std::cerr << "Finding circle" << std::endl;
    auto find_result = find_circle( std::cin, std::cout, circle_point );
    std::cerr << "Found: " << circle_point.first << " " << circle_point.second << std::endl;
    if ( find_result == ACTION::CENTER )
    {
      continue;
    }
    if ( find_result != ACTION::HIT )
    {
      return 0;
    }

    auto center_x = 0;
    std::cerr << "Finding center X" << std::endl;
    auto x_result = find_center_x( std::cin, std::cout, circle_point, center_x );
    if ( x_result == ACTION::CENTER )
    {
      continue;
    }

    auto center_y = 0;
    std::cerr << "Finding center Y" << std::endl;
    auto y_result = find_center_y( std::cin, std::cout, { center_x, circle_point.second }, center_y );
    if ( y_result == ACTION::CENTER )
    {
      continue;
    }
    std::cerr << "Center candidate: " << center_x << " " << center_y << std::endl;
    auto result = std::string();
    std::cout << center_x + 1 << " " << center_y << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
    std::cout << center_x << " " << center_y + 1 << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
    std::cout << center_x + 1 << " " << center_y + 1 << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
    std::cout << center_x - 1 << " " << center_y << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
    std::cout << center_x << " " << center_y - 1 << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
    std::cout << center_x - 1 << " " << center_y - 1 << std::endl;
    std::cin >> result;
    std::cerr << result << std::endl;
  }
  return 0;
}