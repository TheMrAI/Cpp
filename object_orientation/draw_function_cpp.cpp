#include <cmath>
#include <iostream>
#include <memory>

constexpr double resolution{ 4.0 };

class Page
{
public:
  Page(unsigned W, unsigned H): W{ W }, H{ H }
  {
    page = std::make_unique<char[]>(W * H);
    clear();
  }

  Page(const Page&) = delete;
  Page(Page&&) = delete;

  auto operator=(const Page&) -> Page& = delete;
  auto operator=(Page &&) -> Page& = delete;

  ~Page() = default;

  auto width() const -> unsigned
  {
    return W;
  }

  auto height() const -> unsigned
  {
    return H;
  }

  auto setchar(unsigned y, unsigned x, char c) -> bool
  {
    if (y >= H || x >= W)
    {
      return false;
    }
    page[(y * W) + x] = c;
    return true;
  }

  auto clear() -> void
  {
    for (unsigned y = 0; y < H; ++y)
    {
      for (unsigned x = 0; x < W; ++x)
      {
        setchar(y, x, ' ');
      }
    }
  }

  auto print() const -> void
  {
    for (unsigned y = 0; y < H; ++y)
    {
      for (unsigned x = 0; x < W; ++x)
      {
        putchar(page[(y * W) + x]);
      }
      putchar('\n');
    }
  }

private:
  unsigned W;
  unsigned H;
  std::unique_ptr<char[]> page;
};

auto plot(Page& page, char c, double (*f)(double)) -> void
{
  for (int x = 0; x < page.width(); ++x)
  {
    double x_offset = std::floor(page.width() / 2);
    double fx = (x - x_offset) / resolution;
    double fy = f(fx);
    double y_offset = std::floor(page.height() / 2);
    int y = static_cast<int>((fy * resolution) * -1 + y_offset);
    if (y >= 0 && y < page.height())
    {
      page.setchar(y, x, c);
    }
  }
}

class FunctionCall
{
public:
  virtual auto operator()(double) const -> double = 0;
};

void plot(Page& page, char c, FunctionCall const& f)
{
  for (int x = 0; x < page.width(); ++x)
  {
    double x_offset = std::floor(page.width() / 2);
    double fx = (x - x_offset) / resolution;
    double fy = f(fx);
    double y_offset = std::floor(page.height() / 2);
    int y = static_cast<int>((fy * resolution) * -1 + y_offset);
    if (y >= 0 && y < page.height())
    {
      page.setchar(y, x, c);
    }
  }
}

class Sin_times_d: public FunctionCall
{
public:
  explicit Sin_times_d(double d): d{ d }
  {
  }

  auto operator()(double x) const -> double override
  {
    return sin(d * x);
  }

private:
  const double d;
};

auto main() -> int
{
  Page page{ 80, 20 };

  page.clear();

  std::cout << "sin(d * x), d = ?\n";
  double d;
  std::cin >> d;
  Sin_times_d sin_d{ d };

  plot(page, '.', sin_d);
  plot(page, '+', cos);

  page.print();
}
