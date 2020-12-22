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

Noisy::Noisy( Noisy const& /*unused*/ )
{
  std::cout << "Noisy copy\n";
}

Noisy::Noisy( Noisy&& /*unused*/ ) noexcept
{
  std::cout << "Noisy move\n";
}

auto Noisy::operator=( Noisy const & /*unused*/ ) -> Noisy&  // NOLINT
{
  std::cout << "Noisy assignment\n";
  return *this;
}

auto Noisy::operator=( Noisy&& /*unused*/ ) noexcept -> Noisy&
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

auto do_something_with_noisy_cref( Noisy const & /*unused*/ ) -> void
{}

auto do_something_with_noisy_value( Noisy /*unused*/ ) -> void  // NOLINT
{}

auto do_something_with_noisy_rref( Noisy && /*unused*/ ) -> void
{}

}  // namespace mrai