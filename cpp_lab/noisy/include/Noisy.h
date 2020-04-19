#ifndef CPP_NOISY
#define CPP_NOISY

namespace mrai
{
class Noisy
{
public:
  Noisy();
  ~Noisy();
  Noisy(Noisy const& rhs);
  Noisy(Noisy&& rhs) noexcept;
  auto operator=(Noisy const& rhs) -> Noisy&;
  auto operator=(Noisy&& rhs) -> Noisy&;
};

auto create_noisy_on_return() -> Noisy;
auto create_noisy_from_local() -> Noisy;
auto do_something_with_noisy_cref(Noisy const& y) -> void;
auto do_something_with_noisy_value(Noisy y) -> void;
auto do_something_with_noisy_rref(Noisy&& y) -> void;

}  // namespace mrai
#endif  // CPP_NOISY