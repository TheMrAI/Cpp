#include <cmath>
#include <iostream>

class Heron
{
public:
  [[nodiscard]] auto get( double input ) -> double
  {
    x_ = input;
    double guess{ 1.0 };
    while ( !good_enough( guess ) )
    {
      guess = improve( guess );
    }

    return guess;
  }

private:
  [[nodiscard]] auto good_enough( double guess ) const -> bool
  {
    constexpr double epsilon{ 0.001 };
    return std::abs( guess * guess - x_ ) < epsilon;
  }

  [[nodiscard]] auto improve( double guess ) const -> double
  {
    return ( guess + x_ / guess ) / 2.0;
  }

  double x_{ 0.0 };
};

auto main() -> int
{
  std::cout << "Square root using Heron's formuale" << std::endl;

  double input{ 0.0 };
  std::cin >> input;

  Heron h;
  std::cout << h.get( input ) << std::endl;

  return 0;
}