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

TEST(linked_list, pop_back_from_one_element)
{
  linked_list<int> one_element;
  one_element.push_back(33);
  one_element.pop_back();
  ASSERT_TRUE(one_element.empty());
}

TEST(linked_list, pop_back_from_two_elements)
{
  linked_list<int> two_elements;
  two_elements.push_back(33);
  two_elements.push_back(44);
  two_elements.pop_back();
  ASSERT_EQ(two_elements.front(), two_elements.back());
}

TEST(linked_list, pop_back_decreases_size)
{
  linked_list<int> three_elements;
  three_elements.push_back(33);
  three_elements.push_back(44);
  three_elements.push_back(55);
  three_elements.pop_back();
  ASSERT_EQ(2, three_elements.size());
}

TEST(linked_list, pop_front_from_one_element)
{
  linked_list<int> one_element;
  one_element.push_back(33);
  one_element.pop_front();
  ASSERT_TRUE(one_element.empty());
}

TEST(linked_list, pop_front_from_two_elements)
{
  linked_list<int> two_elements;
  two_elements.push_back(33);
  two_elements.push_back(44);
  two_elements.pop_front();
  ASSERT_EQ(two_elements.front(), two_elements.back());
}

TEST(linked_list, pop_front_decreases_size)
{
  linked_list<int> three_elements;
  three_elements.push_back(33);
  three_elements.push_back(44);
  three_elements.push_back(55);
  three_elements.pop_front();
  ASSERT_EQ(2, three_elements.size());
}

TEST(linked_list_iterator, iterator_default_constructable)
{
  auto default_iterator = linked_list<int>::iterator();
}

/*
other linked list operator tests
*/

TEST(linked_list_iterator, empty_list_begin_equals_end)
{
  linked_list<int> empty_list;
  auto begin = empty_list.begin();
  auto end = empty_list.end();
  ASSERT_EQ(begin, end);
}

TEST(linked_list_iterator, empty_list_end_equals_non_empty_end)
{
  linked_list<int> list;
  auto empty_end = list.end();
  list.push_back(42);
  auto end = list.end();
  ASSERT_EQ(empty_end, end);
}

TEST(linked_list_iterator, star_operator_gives_element_reference)
{
  linked_list<int> list;
  list.push_back(42);
  auto begin = list.begin();
  *begin = 24;
  ASSERT_EQ(24, *begin);
}

TEST(linked_list_iterator, arrow_operator_gives_element_reference)
{
  struct test_type
  {
    int data;
  };
  linked_list<test_type*> list;
  auto value = test_type{};
  value.data = 42;
  list.push_back(&value);
  auto begin = list.begin();
  begin->data = 24;
  ASSERT_EQ(24, begin->data);
}