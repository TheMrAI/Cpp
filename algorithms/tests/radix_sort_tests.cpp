#include <gtest/gtest.h>

#include <vector>

#include "radix_sort.h"

using namespace mrai;

TEST(radix_sort, empty_input)
{
    auto input = std::vector<unsigned>{};
    ASSERT_NO_THROW(
        {
            radix_sort(input);
        }
    );
}

TEST(radix_sort, one_element)
{
    auto input = std::vector<unsigned>{1};
    radix_sort(input);
    auto expected = std::vector<unsigned>{1};
    ASSERT_EQ(input, expected);
}

TEST(radix_sort, sorting_numbers_of_different_digit_width)
{
    auto input = std::vector<unsigned>{45, 3, 1223};
    radix_sort(input);
    auto expected = std::vector<unsigned>{3, 45, 1223};
    ASSERT_EQ(input, expected);
}

TEST(radix_sort, sorting_random_numbers)
{
    auto input = std::vector<unsigned>{1, 6663, 234, 45, 3, 1223, 23, 56, 89123, 978};
    radix_sort(input);
    auto expected = std::vector<unsigned>{1, 3, 23, 45, 56, 234, 978, 1223, 6663, 89123};
    ASSERT_EQ(input, expected);
}