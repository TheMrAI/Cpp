#include <gtest/gtest.h>

#include "linked_list.h"

using namespace mrai;

TEST(linked_list, default_constructed_has_0_size)
{
  linked_list<int> empty;
  ASSERT_EQ(0, empty.size());
}

TEST(linked_list, push_back_increases_size_by_one)
{
  linked_list<int> empty;
  empty.push_back(33);
  ASSERT_EQ(1, empty.size());
}

TEST(linked_list, push_front_increases_size_by_one)
{
  linked_list<int> empty;
  empty.push_front(33);
  ASSERT_EQ(1, empty.size());
}

TEST(linked_list, default_constructed_empty_returns_true)
{
  linked_list<int> empty;
  ASSERT_TRUE(empty.empty());
}

TEST(linked_list, for_non_empty_lists_empty_return_false)
{
  linked_list<int> empty;
  empty.push_back(33);
  ASSERT_FALSE(empty.empty());
}

TEST(linked_list, front_returns_first_elements_reference)
{
  linked_list<int> empty;
  empty.push_back(33);
  const auto& front = empty.front();
  ASSERT_EQ(33, front);
}

TEST(linked_list, push_front_appends_to_the_front_of_the_list)
{
  linked_list<int> simple;
  simple.push_back(33);
  simple.push_front(11);
  const auto& front = simple.front();
  ASSERT_EQ(11, front);
}

TEST(linked_list, first_element_modified_trough_first_reference)
{
  linked_list<int> empty;
  empty.push_back(33);
  auto& front = empty.front();
  front = 11;
  ASSERT_EQ(11, empty.front());
}

TEST(linked_list, back_returns_last_element)
{
  linked_list<int> three_elements;
  three_elements.push_back(33);
  three_elements.push_back(44);
  three_elements.push_back(55);
  const auto& back = three_elements.back();
  ASSERT_EQ(55, back);
}

TEST(linked_list, last_element_modified_trough_back_reference)
{
  linked_list<int> three_elements;
  three_elements.push_back(33);
  three_elements.push_back(44);
  three_elements.push_back(55);
  auto& back = three_elements.back();
  back = 123;
  ASSERT_EQ(123, three_elements.back());
}