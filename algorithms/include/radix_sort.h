#ifndef ALGORITHMS_RADIX_SORT
#define ALGORITHMS_RADIX_SORT

#include <algorithm>
#include <cmath>
#include <vector>

namespace mrai
{

auto radix_sort(std::vector<unsigned> & input) -> void
{
    if(input.empty())
    {
        return;
    }
    static constexpr auto final_decimal = std::pow(10, (std::numeric_limits<unsigned>::digits10 - 1));

    unsigned digit = 1;
    while(true)
    {
        std::stable_sort(input.begin(), input.end(), 
        [&digit](auto lhs, auto rhs)
        {
            auto lhs_digit = (lhs / digit) % 10;
            auto rhs_digit = (rhs / digit) % 10;
            return lhs_digit < rhs_digit;
        });

        if(digit == final_decimal)
        {
            break;
        }
        digit *= 10;
    }
}

} // namespace mrai

#endif // ALGORITHMS_RADIX_SORT