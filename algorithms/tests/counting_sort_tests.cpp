#include <gtest/gtest.h>

#include <vector>

#include "counting_sort.h"

using namespace mrai;

TEST(counting_sort, empty_input)
{
    auto input = std::vector<unsigned>{};
    auto result = counting_sort(input, 0);
    ASSERT_EQ(result.size(), 0);
}

TEST(counting_sort, maximum_value_at_limit)
{
    auto input = std::vector<unsigned>{3, 1, 2};
    ASSERT_THROW(
        {
            counting_sort(input, std::numeric_limits<unsigned>::max());
        }
        , std::length_error
    );
    
}

TEST(counting_sort, 3_elements_maximum_element_set_as_maximum_from_the_input)
{
    auto input = std::vector<unsigned>{3, 1, 2};
    auto result = counting_sort(input, 3);
    auto expected = std::vector<unsigned>{1, 2, 3};
    ASSERT_EQ(result, expected);
}

TEST(counting_sort, counting_sort_on_random_input)
{
    auto input = std::vector<unsigned>{ 16, 96, 33, 20, 6,  83, 64, 71, 64, 55,
                                    8,  14, 19, 36, 25, 90, 70, 6,  1,  76,
                                    46, 51, 93, 61, 19, 49, 13, 92, 77, 69 };
    auto result = counting_sort(input, 100);
    auto expected = std::vector<unsigned>{ 1,  6,  6,  8,  13, 14, 16, 19, 19, 20,
                                        25, 33, 36, 46, 49, 51, 55, 61, 64, 64,
                                        69, 70, 71, 76, 77, 83, 90, 92, 93, 96 };
    ASSERT_EQ(result, expected);
}