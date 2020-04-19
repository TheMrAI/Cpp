#include <gtest/gtest.h>

#include "red_black_tree.h"

using namespace mrai;

class default_constructed_red_black_tree: public ::testing::Test
{
protected:
  rb_tree<int> tree;
};

TEST_F(default_constructed_red_black_tree, cbegin_returns_cend)
{
  ASSERT_EQ(tree.cend(), tree.cbegin());
}

TEST_F(default_constructed_red_black_tree, empty_is_true)
{
  ASSERT_TRUE(tree.empty());
}

TEST_F(default_constructed_red_black_tree, size_is_zero)
{
  ASSERT_EQ(tree.size(), 0);
}