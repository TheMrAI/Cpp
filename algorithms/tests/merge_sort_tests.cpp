#include <gtest/gtest.h>

#include "merge_sort.h"

using namespace mrai;

TEST(in_place_merge, empty_input)
{
  std::vector<int> data{};
  EXPECT_NO_THROW(in_place_merge(data.begin(), data.end(), data.end()););
  EXPECT_EQ(data.size(), 0);
}

TEST(in_place_merge, 2_elements_in_order_no_change)
{
  std::vector<int> data{ 1, 2 };
  EXPECT_NO_THROW(in_place_merge(data.begin(), ++data.begin(), data.end()););
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 2_elements_out_of_order_change)
{
  std::vector<int> data{ 2, 1 };
  EXPECT_NO_THROW(in_place_merge(data.begin(), ++data.begin(), data.end()););
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(in_place_merge, 5_elements_as_if_partially_sorted)
{
  std::vector<int> data{ 2, 4, 1, 3, 5 };
  EXPECT_NO_THROW(
      in_place_merge(data.begin(), std::next(data.begin(), 2), data.end()););
  std::vector<int> expected{ 1, 2, 3, 4, 5 };
  ASSERT_EQ(data, expected);
}

TEST(merge_sort, empty_input)
{
  std::vector<int> data{};
  EXPECT_NO_THROW(merge_sort(data.begin(), data.end()););
  EXPECT_EQ(data.size(), 0);
}

TEST(merge_sort, 2_elements_out_of_order)
{
  std::vector<int> data{ 2, 1 };
  merge_sort(data.begin(), data.end());
  std::vector<int> expected{ 1, 2 };
  ASSERT_EQ(data, expected);
}

TEST(merge_sort, 5_random_elements)
{
  std::vector<int> data{ 3, 1, 4, 2, 5 };
  merge_sort(data.begin(), data.end());
  std::vector<int> expected{ 1, 2, 3, 4, 5 };
  ASSERT_EQ(data, expected);
}