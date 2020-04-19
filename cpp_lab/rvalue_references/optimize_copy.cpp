#include <iostream>

#include "Noisy.h"

auto main() -> int
{
  std::cout << "create_noisy_on_return()\n";
  auto on_return = mrai::create_noisy_on_return();
  std::cout << "create_noisy_from_local()\n";
  auto from_local = mrai::create_noisy_from_local();

  std::cout << "do_something_with_noisy_cref()\n";
  mrai::do_something_with_noisy_cref(mrai::Noisy());
  std::cout << "do_something_with_noisy_value()\n";
  mrai::do_something_with_noisy_value(mrai::Noisy());
  std::cout << "do_something_with_noisy_rref()\n";
  mrai::do_something_with_noisy_rref(mrai::Noisy());
  std::cout << std::endl;
}