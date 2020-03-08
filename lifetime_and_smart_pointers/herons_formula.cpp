#include <cmath>
#include <iostream>

class Heron
{
public:
  auto get(double input) -> double
  {
    x_ = input;
    double guess{ 1.0 };
    while (!good_enough(guess))
    {
      guess = improve(guess);
    }

    return guess;
  }

private:
  auto good_enough(double guess) const -> double
  {
    constexpr double epsilon{ 0.001 };

    return std::abs(guess * guess - x_) < epsilon;
  }

  auto improve(double guess) const -> double
  {
    return (guess + x_ / guess) / 2.0;
  }

  double x_{ 0.0 };
};

auto main() -> int
{
  std::cout << "Square root using Heron's formuale" << std::endl;

  double input{ 0.0 };
  std::cin >> input;

  Heron h;
  std::cout << h.get(input) << std::endl;

  return 0;
}