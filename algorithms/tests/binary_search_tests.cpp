#include <gtest/gtest.h>

#include "binary_search.h"

using namespace mrai;

TEST(binary_search, empty_input_returns_false)
{
  std::vector<int> data;
  ASSERT_FALSE(find(data, 3));
}

TEST(binary_search, single_element_is_what_we_search_for)
{
  std::vector<int> data = { 3 };
  ASSERT_TRUE(find(data, 3));
}

class binary_search_finding: public ::testing::Test
{
public:
  binary_search_finding()
  {
    data_ = { 1, 2, 3, 5, 14, 56, 111, 567, 784, 967, 1113, 5321, 6775 };
  }

protected:
  std::vector<int> data_;
};

TEST_F(binary_search_finding, find_first_element)
{
  ASSERT_TRUE(find(data_, 1));
}

TEST_F(binary_search_finding, find_middle_element)
{
  ASSERT_TRUE(find(data_, 111));
}

TEST_F(binary_search_finding, find_last_element)
{
  ASSERT_TRUE(find(data_, 6775));
}

TEST_F(binary_search_finding, find_random_element)
{
  ASSERT_TRUE(find(data_, 967));
}

TEST_F(binary_search_finding, find_not_available_negative_element)
{
  ASSERT_FALSE(find(data_, -10));
}

TEST_F(binary_search_finding, find_not_available_positive_element)
{
  ASSERT_FALSE(find(data_, 633));
}