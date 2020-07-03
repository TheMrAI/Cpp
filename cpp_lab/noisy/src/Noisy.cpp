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

Noisy::Noisy( Noisy const& )
{
  std::cout << "Noisy copy\n";
}

Noisy::Noisy( Noisy&& ) noexcept
{
  std::cout << "Noisy move\n";
}

auto Noisy::operator=( Noisy const& ) -> Noisy&
{
  std::cout << "Noisy assignment\n";
  return *this;
}

auto Noisy::operator=( Noisy && ) -> Noisy&
{
  std::cout << "Noisy move assignement\n";
  return *this;
}

auto create_noisy_on_return() -> Noisy
{
  return Noisy();
}

auto create_noisy_from_local() -> Noisy
{
  Noisy y;
  return y;
}

auto do_something_with_noisy_cref( Noisy const& ) -> void
{}

auto do_something_with_noisy_value( Noisy ) -> void
{}

auto do_something_with_noisy_rref( Noisy && ) -> void
{}

}  // namespace mrai