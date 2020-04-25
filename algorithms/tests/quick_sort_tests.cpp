#include <gtest/gtest.h>

#include <vector>

#include "quick_sort.h"

using namespace mrai;

TEST(quicksort_lr, empty_input)
{
  auto input = std::vector<int>{};
  quicksort_lr(input.begin(), input.end());
  ASSERT_TRUE(input.empty());
}

TEST(quicksort_lr, 1_element_in_input)
{
  auto input = std::vector<int>{ 1 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, 2_elements_in_order)
{
  auto input = std::vector<int>{ 1, 2 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1, 2 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, 2_elements_out_of_order)
{
  auto input = std::vector<int>{ 2, 1 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1, 2 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, 4_elements_in_order)
{
  auto input = std::vector<int>{ 1, 2, 3, 4 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1, 2, 3, 4 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, 4_elements_out_of_order)
{
  auto input = std::vector<int>{ 2, 1, 4, 3 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1, 2, 3, 4 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, 6_elements_out_of_order)
{
  auto input = std::vector<int>{ 7, 6, 1, 2, 8, 5 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1, 2, 5, 6, 7, 8 };
  ASSERT_EQ(input, expected);
}

TEST(quicksort_lr, on_30_element_random_sequence)
{
  auto input = std::vector<int>{ 16, 96, 33, 20, 6,  83, 64, 71, 64, 55,
                                 8,  14, 19, 36, 25, 90, 70, 6,  1,  76,
                                 46, 51, 93, 61, 19, 49, 13, 92, 77, 69 };
  quicksort_lr(input.begin(), input.end());
  auto expected = std::vector<int>{ 1,  6,  6,  8,  13, 14, 16, 19, 19, 20,
                                    25, 33, 36, 46, 49, 51, 55, 61, 64, 64,
                                    69, 70, 71, 76, 77, 83, 90, 92, 93, 96 };
  ASSERT_EQ(input, expected);
}