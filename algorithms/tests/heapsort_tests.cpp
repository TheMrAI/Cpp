#include <gtest/gtest.h>

#include <vector>

#include "heapsort.h"

using namespace mrai;

// heapsort
TEST(heapsort, one_element)
{
  std::vector<int> data{1};
  heapsort(data.begin(), data.end());
  auto expected = std::vector<int>{1};
  ASSERT_EQ(data, expected);
}

TEST(heapsort, random_input)
{
  std::vector<int> data{3, 10, 7, -1, 1, 0, 2, 5, 4, 6, 8, 9};
  heapsort(data.begin(), data.end());
  auto expected = std::vector<int>{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(data, expected);
}

// restore_heap_property_from
TEST(restore_heap_property_from, one_child)
{
  std::vector<int> data{1, 3};
  restore_heap_property_from(data.begin(), data.end(), data.begin());
  auto expected = std::vector<int>{3, 1};
  ASSERT_EQ(data, expected);
}

TEST(restore_heap_property_from, restore_heap_from_a_faulty_element)
{
  std::vector<int> data{20, 1, 16, 14, 7, 9, 11, 5, 3};
  restore_heap_property_from(data.begin(), data.end(), ++data.begin());
  auto expected = std::vector<int>{20, 14, 16, 5, 7, 9, 11, 1, 3};
  ASSERT_EQ(data, expected);
}

// manual_make_heap
TEST(manual_make_heap, random_input)
{
  auto data = std::vector<int>{5, 8, 3, 1, 7};
  manual_make_heap(data.begin(), data.end());
  auto expected = std::vector<int>{8, 7, 3, 1, 5};
  ASSERT_EQ(data, expected);
}

// manual_sort_heap
TEST(manual_sort_heap, input_heap_sorted_into_ascending_order)
{
    auto data = std::vector<int>{20, 14, 16, 5, 7, 9, 11, 1, 3};
    manual_sort_heap(data.begin(), data.end());
    auto expected = std::vector<int>{1, 3, 5, 7, 9, 11, 14, 16, 20};
    ASSERT_EQ(data, expected);
}

// manual_heapsort
TEST(manual_heapsort, one_element)
{
  std::vector<int> data{1};
  manual_heapsort(data.begin(), data.end());
  auto expected = std::vector<int>{1};
  ASSERT_EQ(data, expected);
}

TEST(manual_heapsort, random_input)
{
  std::vector<int> data{3, 10, 7, -1, 1, 0, 2, 5, 4, 6, 8, 9};
  manual_heapsort(data.begin(), data.end());
  auto expected = std::vector<int>{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(data, expected);
}

TEST(manual_heapsort, sanity_test_with_heapsort)
{
  auto data = std::vector<int>{56, 32, 1, 0, -23, -6, 998, 54, 11, 7, 4, -2};
  auto data_for_manual = data;
  heapsort(data.begin(), data.end());
  manual_heapsort(data_for_manual.begin(), data_for_manual.end());
  ASSERT_EQ(data, data_for_manual);
}