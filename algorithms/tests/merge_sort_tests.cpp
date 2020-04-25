#include <gtest/gtest.h>

#include <iterator>

#include "merge_sort.h"

using namespace mrai;

TEST(merge, empty_input)
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{};
  auto rhs_data = std::vector<int>{};
  merge(lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(),
        std::back_inserter(output));
  ASSERT_TRUE(output.empty());
}

TEST(merge, only_lhs_input_has_values)
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{ 1, 2, 3 };
  auto rhs_data = std::vector<int>{};
  merge(lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(),
        std::back_inserter(output));
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ(output, expected);
}

TEST(merge, only_rhs_input_has_values)
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{};
  auto rhs_data = std::vector<int>{ 1, 2, 3 };
  merge(lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(),
        std::back_inserter(output));
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ(output, expected);
}

TEST(merge, proper_merging)
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{ 0, 4, 6, 9, 15 };
  auto rhs_data = std::vector<int>{ 1, 2, 3, 8, 10 };
  merge(lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(),
        std::back_inserter(output));
  auto expected = std::vector<int>{ 0, 1, 2, 3, 4, 6, 8, 9, 10, 15 };
  ASSERT_EQ(output, expected);
}

TEST(merge_sort, empty_input)
{
  auto input = std::vector<int>{};
  auto output = std::vector<int>{};
  merge_sort(input.cbegin(), input.cend(), std::back_inserter(output));
  auto expected = std::vector<int>{};
  ASSERT_EQ(output, expected);
}

TEST(merge_sort, already_sorted_input_no_change)
{
  auto input = std::vector<int>{ 1, 2, 3, 4, 5 };
  auto output = std::vector<int>{};
  merge_sort(input.cbegin(), input.cend(), std::back_inserter(output));
  auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };
  ASSERT_EQ(output, expected);
}

TEST(merge_sort, non_sorted_input_gets_sorted)
{
  auto input = std::vector<int>{ 3, 1, 5, 2, 4 };
  auto output = std::vector<int>{};
  merge_sort(input.cbegin(), input.cend(), std::back_inserter(output));
  auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };
  ASSERT_EQ(output, expected);
}

TEST(in_place_merge, empty_input)
{
  std::vector<int> data{};
  in_place_merge(data.begin(), data.end(), data.end());
  EXPECT_EQ(data.size(), 0);
}

TEST(in_place_merge, one_element)
{
  std::vector<int> data{ 1 };
  in_place_merge(data.begin(), data.end(), data.end());
  std::vector<int> expected{ 1 };
  EXPECT_EQ(data, expected);
}

TEST(in_place_merge, 2_elements_in_order_no_change)
{
  std::vector<int> data{ 1, 2 };
  in_place_merge(data.begin(), ++data.begin(), data.end());
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 2_elements_out_of_order_change)
{
  std::vector<int> data{ 2, 1 };
  in_place_merge(data.begin(), ++data.begin(), data.end());
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 3_elements_out_of_order_change)
{
  std::vector<int> data{ 3, 1, 2 };
  in_place_merge(data.begin(), ++data.begin(), data.end());
  std::vector<int> expected{ 1, 2, 3 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 5_elements_as_if_partially_sorted)
{
  std::vector<int> data{ 2, 4, 1, 3, 5 };
  in_place_merge(data.begin(), std::next(data.begin(), 2), data.end());
  std::vector<int> expected{ 1, 2, 3, 4, 5 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 6_elements_as_if_partially_sorted)
{
  std::vector<int> data{ 1, 6, 7, 2, 5, 8 };
  in_place_merge(data.begin(), std::next(data.begin(), 3), data.end());
  std::vector<int> expected{ 1, 2, 5, 6, 7, 8 };
  ASSERT_EQ(data, expected);
}

TEST(merge_sort_in_place, empty_input)
{
  std::vector<int> data{};
  merge_sort_in_place(data.begin(), data.end());
  EXPECT_EQ(data.size(), 0);
}

TEST(merge_sort_in_place, 2_elements_out_of_order)
{
  std::vector<int> data{ 2, 1 };
  merge_sort_in_place(data.begin(), data.end());
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(merge_sort_in_place, 3_elements_out_of_order)
{
  std::vector<int> data{ 2, 3, 1 };
  merge_sort_in_place(data.begin(), data.end());
  std::vector<int> expected{ 1, 2, 3 };
  ASSERT_EQ(data, expected);
}

TEST(merge_sort_in_place, 6_random_elements)
{
  std::vector<int> data{ 7, 6, 1, 2, 8, 5 };
  merge_sort_in_place(data.begin(), data.end());
  std::vector<int> expected{ 1, 2, 5, 6, 7, 8 };
  ASSERT_EQ(data, expected);
}