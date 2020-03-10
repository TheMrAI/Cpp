#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
/*
In JavaScript:
function derival(f) {
    var dx = 0.001;
    function derivalt(x) {
        return (f(x+dx) - f(x)) / dx;
    }

    return derivalt;
}
*/

// f(x)=ax2+bx+c
class Parabola
{
public:
  Parabola(double a, double b, double c): a_{ a }, b_{ b }, c_{ c }
  {
  }

  auto operator()(double x) -> double
  {
    return a_ * std::pow(x, 2.0) + b_ * x + c_;
  }

private:
  const double a_;
  const double b_;
  const double c_;
};

template <typename RETURN, typename ARGUMENT>
class Derival
{
public:
  using callable = std::function<RETURN(ARGUMENT)>;

  Derival(callable function): function_{ function }
  {
  }

  auto operator()(ARGUMENT x) -> RETURN
  {
    const auto dx = 0.001;
    return (function_(x + dx) - function_(x)) / dx;
  }

private:
  callable function_;
};

auto main() -> int
{
  Derival<double, double> my_cos{ sin };

  constexpr auto PI = 3.1415;
  const auto diferential_quotient = 0.1;
  for (double f = 0; f < PI; f += diferential_quotient)
  {
    std::cout << std::setw(20) << my_cos(f) - cos(f)
              << std::endl;  // should be close to zero
  }

  Parabola p1{ 0.5, 2.3, -5 }; /* 0.5x^2 + 2.3x - 5 */
  Derival<double, double> p1_der{ p1 };

  Parabola p2{ 0, 1, 2.3 }; /* x + 2.3, p1 derivative */
  for (double f = 0; f < 3.0; f += 0.1)
  {
    std::cout << std::setw(20) << p1_der(f) - p2(f)
              << std::endl;  // should be close to zero
  }

  return 0;
}