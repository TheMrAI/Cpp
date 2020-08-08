#include <gtest/gtest.h>

#include "maximal_subarray.h"

using namespace mrai;

TEST(kadane, empty_input_returns_zero)
{
  auto input = std::vector<int>();
  auto result = kadane(input);
  ASSERT_EQ(result, 0);
}

TEST(kadane, all_negative_input_returns_zero)
{
  auto input = std::vector<int>{ -1, -2, -3, -4, -5 };
  auto result = kadane(input);
  ASSERT_EQ(result, 0);
}

TEST(kadane, maximal_at_the_beggining)
{
  auto input = std::vector<int>{ 7, 8, 9, -10, -13, -20, 3, 5 };
  auto result = kadane(input);
  ASSERT_EQ(result, 24);
}

TEST(kadane, maximal_in_the_middle)
{
  auto input =
      std::vector<int>{ 1, 3, 4, -10, -5, 5, 7, 9, 11, -13, -4, -2, 3, 4 };
  auto result = kadane(input);
  ASSERT_EQ(result, 32);
}

TEST(kadane, maximal_at_the_end)
{
  auto input = std::vector<int>{ -1, -2, -3, -4, -5, 78, 3 };
  auto result = kadane(input);
  ASSERT_EQ(result, 81);
}

TEST(kadane, oscillating_sum_sequence)
{
  auto input = std::vector<int>{ -3, 2, 4, -6, 3, 4, -5, 7, 2, -1 };
  auto result = kadane(input);
  ASSERT_EQ(result, 11);
}