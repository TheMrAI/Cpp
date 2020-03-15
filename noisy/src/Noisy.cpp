#include "Noisy.h"

#include <iostream>

namespace mrai
{
Noisy::Noisy()
{
  std::cout << "Noisy ctor\n";
}

Noisy::~Noisy()
{
  std::cout << "Noisy dtor\n";
}

Noisy::Noisy(Noisy const&)
{
  std::cout << "Noisy copy\n";
}

Noisy::Noisy(Noisy&&) noexcept
{
  std::cout << "Noisy move\n";
}

Noisy& Noisy::operator=(Noisy const&)
{
  std::cout << "Noisy assignment\n";
  return *this;
}

Noisy& Noisy::operator=(Noisy&&)
{
  std::cout << "Noisy move assignement\n";
  return *this;
}

Noisy create_noisy_on_return()
{
  return Noisy();
}

Noisy create_noisy_from_local()
{
  Noisy y;
  return y;
}

void do_something_with_noisy_cref(Noisy const)
{
}

void do_something_with_noisy_value(Noisy)
{
}

void do_something_with_noisy_rref(Noisy&&)
{
}

}  // namespace mrai