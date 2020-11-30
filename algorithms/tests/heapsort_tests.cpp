#include <gtest/gtest.h>

#include <vector>

#include "heapsort.h"

using namespace mrai;

TEST(heapsort, empty_input_returns_empty_input)
{
  std::vector<int> data;
  auto result = heapsort(data);
  ASSERT_TRUE(result.empty());
}

TEST(heapsort, one_element)
{
  std::vector<int> data{1};
  auto result = heapsort(data);
  auto expected = std::vector<int>{1};
  ASSERT_EQ(result, expected);
}

TEST(heapsort, random_input)
{
  std::vector<int> data{3, 10, 7, -1, 1, 0, 2, 5, 4, 6, 8, 9};
  auto result = heapsort(data);
  auto expected = std::vector<int>{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(result, expected);
}