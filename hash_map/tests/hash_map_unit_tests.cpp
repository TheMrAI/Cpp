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

TEST_F(default_constructed_hash_map, find_returns_end)
{
  ASSERT_EQ(map.find(3), map.end());
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

TEST_F(default_constructed_hash_map, bucket_index_for_19_is_19)
{
  ASSERT_EQ(map.bucket(19), 19);
}

TEST_F(default_constructed_hash_map, bucket_index_for_25_is_19)
{
  ASSERT_EQ(map.bucket(25), 5);
}

TEST_F(default_constructed_hash_map, load_factor_is_zero)
{
  ASSERT_EQ(map.load_factor(), 0);
}

TEST_F(default_constructed_hash_map, maximum_load_factor_is_3)
{
  ASSERT_FLOAT_EQ(map.max_load_factor(), 3.0f);
}

TEST_F(default_constructed_hash_map, maximum_load_factor_set_to_1)
{
  map.max_load_factor(1.0f);
  ASSERT_FLOAT_EQ(map.max_load_factor(), 1.0f);
}

TEST_F(default_constructed_hash_map, begin_and_end_iterators_are_equal)
{
  ASSERT_EQ(map.begin(), map.end());
}

class hash_map_iterator_traits: public ::testing::Test
{
protected:
  hash_map_iterator_traits()
  {
  }

  hash_map<int, std::string> map;
};

TEST_F(hash_map_iterator_traits, iterator_category)
{
  ASSERT_EQ(typeid(std::iterator_traits<
                   hash_map<int, std::string>::iterator>::iterator_category),
            typeid(std::forward_iterator_tag));
}

TEST_F(hash_map_iterator_traits, reference)
{
  ASSERT_EQ(typeid(std::iterator_traits<
                   hash_map<int, std::string>::iterator>::reference),
            typeid(std::pair<const int, std::string>&));
}

TEST_F(hash_map_iterator_traits, pointer)
{
  ASSERT_EQ(
      typeid(
          std::iterator_traits<hash_map<int, std::string>::iterator>::pointer),
      typeid(std::pair<const int, std::string>*));
}

TEST_F(hash_map_iterator_traits, value_type)
{
  ASSERT_EQ(typeid(std::iterator_traits<
                   hash_map<int, std::string>::iterator>::value_type),
            typeid(std::pair<const int, std::string>));
}

TEST_F(hash_map_iterator_traits, difference_type)
{
  ASSERT_EQ(typeid(std::iterator_traits<
                   hash_map<int, std::string>::iterator>::difference_type),
            typeid(void));
}

class hash_map_with_one_element: public ::testing::Test
{
protected:
  hash_map_with_one_element()
  {
    map.insert({ 0, "zero" });
  }

  hash_map<int, std::string> map;
};

TEST_F(hash_map_with_one_element, empty_is_false)
{
  ASSERT_FALSE(map.empty());
}

TEST_F(hash_map_with_one_element, size_is_one)
{
  ASSERT_EQ(map.size(), 1);
}

TEST_F(hash_map_with_one_element, contains_returns_true)
{
  ASSERT_TRUE(map.contains(0));
}

TEST_F(hash_map_with_one_element, find_only_element)
{
  auto target = map.find(0);
  ASSERT_EQ(target->first, 0);
  ASSERT_EQ(target->second, "zero");
}

TEST_F(hash_map_with_one_element, change_value_for_the_only_element)
{
  auto target = map.find(0);
  target->second = "potato";
  target = map.find(0);
  ASSERT_EQ(target->second, "potato");
}

TEST_F(hash_map_with_one_element, bucket_count_is_20)
{
  ASSERT_EQ(map.bucket_count(), 20);
}

TEST_F(hash_map_with_one_element, zeroth_bucket_size_is_one)
{
  ASSERT_EQ(map.bucket_size(0), 1);
}

TEST_F(hash_map_with_one_element, begin_gives_the_only_element)
{
  auto only_element = map.begin();
  ASSERT_EQ(only_element->first, 0);
  ASSERT_EQ(only_element->second, "zero");
}

TEST_F(hash_map_with_one_element, begin_incremented_once_is_end)
{
  ASSERT_EQ(++(map.begin()), map.end());
}