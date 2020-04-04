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

TEST_F(default_constructed_hash_map, contains_returns_false)
{
  ASSERT_FALSE(map.contains(3));
}

TEST_F(default_constructed_hash_map, bucket_count_is_20)
{
  ASSERT_EQ(map.bucket_count(), 20);
}

TEST_F(default_constructed_hash_map,
       max_bucket_count_is_the_maximum_number_size_t_can_take_on_the_system)
{
  ASSERT_EQ(map.max_bucket_count(), std::numeric_limits<std::size_t>::max());
}

TEST_F(default_constructed_hash_map, random_bucket_size_within_range_is_zero)
{
  ASSERT_EQ(map.bucket_size(5), 0);
}

TEST_F(default_constructed_hash_map,
       bucket_size_outside_of_bucket_count_is_undefined_non_throwing)
{
  ASSERT_NO_THROW({ map.bucket_size(25); });
}

TEST_F(default_constructed_hash_map, bucket_index_for_0_is_0)
{
  ASSERT_EQ(map.bucket(0), 0);
}
