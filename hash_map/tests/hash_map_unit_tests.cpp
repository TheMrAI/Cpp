#include <gtest/gtest.h>

#include "hash_map.h"

using namespace mrai;

class default_constructed_hash_map: public ::testing::Test
{
protected:
  default_constructed_hash_map()
  {
  }

  hash_map<int, std::string> map;
};

TEST_F(default_constructed_hash_map, empty_is_true)
{
  ASSERT_TRUE(map.empty());
}

TEST_F(default_constructed_hash_map, size_is_zero)
{
  ASSERT_EQ(map.size(), 0);
}

TEST_F(default_constructed_hash_map, bucket_count_is_zero)
{
  ASSERT_EQ(map.bucket_count(), 0);
}

TEST_F(default_constructed_hash_map, max_bucket_count_is_20)
{
  ASSERT_EQ(map.max_bucket_count(), 20);
}