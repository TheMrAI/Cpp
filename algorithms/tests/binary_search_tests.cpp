#include <gtest/gtest.h>

#include <vector>

#include "binary_search.h"

using namespace mrai;

TEST(recursive_binary_search, empty_input_returns_false)
{
  std::vector<int> data;
  ASSERT_FALSE(recursive_binary_search(data.begin(), data.end(), 3));
}

TEST(recursive_binary_search, single_element_is_what_we_search_for)
{
  std::vector<int> data = { 3 };
  ASSERT_TRUE(recursive_binary_search(data.begin(), data.end(), 3));
}

class recursive_binary_search_finding: public ::testing::Test
{
protected:
  recursive_binary_search_finding()
  {
    data_ = { 1, 2, 3, 5, 14, 56, 111, 567, 784, 967, 1113, 5321, 6775 };
  }

  std::vector<int> data_;
};

TEST_F(recursive_binary_search_finding, find_first_element)
{
  ASSERT_TRUE(recursive_binary_search(data_.begin(), data_.end(), 1));
}

TEST_F(recursive_binary_search_finding, find_middle_element)
{
  ASSERT_TRUE(recursive_binary_search(data_.begin(), data_.end(), 111));
}

TEST_F(recursive_binary_search_finding, find_last_element)
{
  ASSERT_TRUE(recursive_binary_search(data_.begin(), data_.end(), 6775));
}

TEST_F(recursive_binary_search_finding, find_random_element)
{
  ASSERT_TRUE(recursive_binary_search(data_.begin(), data_.end(), 967));
}

TEST_F(recursive_binary_search_finding, find_not_available_negative_element)
{
  ASSERT_FALSE(recursive_binary_search(data_.begin(), data_.end(), -10));
}

TEST_F(recursive_binary_search_finding, find_not_available_positive_element)
{
  ASSERT_FALSE(recursive_binary_search(data_.begin(), data_.end(), 633));
}

TEST(sequential_binary_search, empty_input_returns_false)
{
  std::vector<int> data;
  ASSERT_FALSE(sequential_binary_search(data.begin(), data.end(), 3));
}

TEST(sequential_binary_search, single_element_is_what_we_search_for)
{
  std::vector<int> data = { 3 };
  ASSERT_TRUE(sequential_binary_search(data.begin(), data.end(), 3));
}

class sequential_binary_search_finding: public ::testing::Test
{
protected:
  sequential_binary_search_finding()
  {
    data_ = { 1, 2, 3, 5, 14, 56, 111, 567, 784, 967, 1113, 5321, 6775 };
  }

  std::vector<int> data_;
};

TEST_F(sequential_binary_search_finding, find_first_element)
{
  ASSERT_TRUE(sequential_binary_search(data_.begin(), data_.end(), 1));
}

TEST_F(sequential_binary_search_finding, find_middle_element)
{
  ASSERT_TRUE(sequential_binary_search(data_.begin(), data_.end(), 111));
}

TEST_F(sequential_binary_search_finding, find_last_element)
{
  ASSERT_TRUE(sequential_binary_search(data_.begin(), data_.end(), 6775));
}

TEST_F(sequential_binary_search_finding, find_random_element)
{
  ASSERT_TRUE(sequential_binary_search(data_.begin(), data_.end(), 967));
}

TEST_F(sequential_binary_search_finding, find_not_available_negative_element)
{
  ASSERT_FALSE(sequential_binary_search(data_.begin(), data_.end(), -10));
}