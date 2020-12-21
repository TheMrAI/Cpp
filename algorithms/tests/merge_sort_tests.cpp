#include <gtest/gtest.h>

#include <iterator>
#include <vector>

#include "merge_sort.h"

using namespace mrai;

TEST( merge, empty_input )
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{};
  auto rhs_data = std::vector<int>{};
  merge( lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(), std::back_inserter( output ) );
  ASSERT_TRUE( output.empty() );
}

TEST( merge, only_lhs_input_has_values )
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{ 1, 2, 3 };
  auto rhs_data = std::vector<int>{};
  merge( lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ( output, expected );
}

TEST( merge, only_rhs_input_has_values )
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{};
  auto rhs_data = std::vector<int>{ 1, 2, 3 };
  merge( lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ( output, expected );
}

TEST( merge, proper_merging )
{
  auto output = std::vector<int>{};
  auto lhs_data = std::vector<int>{ 0, 4, 6, 9, 15 };
  auto rhs_data = std::vector<int>{ 1, 2, 3, 8, 10 };
  merge( lhs_data.begin(), lhs_data.end(), rhs_data.begin(), rhs_data.end(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 0, 1, 2, 3, 4, 6, 8, 9, 10, 15 };
  ASSERT_EQ( output, expected );
}

TEST( merge_sort, empty_input )
{
  auto input = std::vector<int>{};
  auto output = std::vector<int>{};
  merge_sort( input.cbegin(), input.cend(), std::back_inserter( output ) );
  auto expected = std::vector<int>{};
  ASSERT_EQ( output, expected );
}

TEST( merge_sort, already_sorted_input_no_change )
{
  auto input = std::vector<int>{ 1, 2, 3, 4, 5 };
  auto output = std::vector<int>{};
  merge_sort( input.cbegin(), input.cend(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };
  ASSERT_EQ( output, expected );
}

TEST( merge_sort, non_sorted_input_gets_sorted )
{
  auto input = std::vector<int>{ 3, 1, 5, 2, 4 };
  auto output = std::vector<int>{};
  merge_sort( input.cbegin(), input.cend(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };
  ASSERT_EQ( output, expected );
}

TEST( merge_sort, on_30_element_random_sequence )
{
  auto input = std::vector<int>{ 16, 96, 33, 20, 6,  83, 64, 71, 64, 55, 8,  14, 19, 36, 25,
                                 90, 70, 6,  1,  76, 46, 51, 93, 61, 19, 49, 13, 92, 77, 69 };
  auto output = std::vector<int>{};
  merge_sort( input.begin(), input.end(), std::back_inserter( output ) );
  auto expected = std::vector<int>{ 1,  6,  6,  8,  13, 14, 16, 19, 19, 20, 25, 33, 36, 46, 49,
                                    51, 55, 61, 64, 64, 69, 70, 71, 76, 77, 83, 90, 92, 93, 96 };
  ASSERT_EQ( output, expected );
}

TEST( in_place_merge, empty_input )
{
  auto input = std::vector<int>{};
  in_place_merge( input.begin(), input.end(), input.end() );
  EXPECT_EQ( input.size(), 0 );
}

TEST( in_place_merge, one_element )
{
  auto input = std::vector<int>{ 1 };
  in_place_merge( input.begin(), input.end(), input.end() );
  auto expected = std::vector<int>{ 1 };
  EXPECT_EQ( input, expected );
}

TEST( in_place_merge, 2_elements_in_order_no_change )
{
  auto input = std::vector<int>{ 1, 2 };
  in_place_merge( input.begin(), ++input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2 };
  ASSERT_EQ( input, expected );
}

TEST( in_place_merge, 2_elements_out_of_order_change )
{
  auto input = std::vector<int>{ 2, 1 };
  in_place_merge( input.begin(), ++input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2 };
  ASSERT_EQ( input, expected );
}

TEST( in_place_merge, 3_elements_out_of_order_change )
{
  auto input = std::vector<int>{ 3, 1, 2 };
  in_place_merge( input.begin(), ++input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ( input, expected );
}

TEST( in_place_merge, 5_elements_as_if_partially_sorted )
{
  auto input = std::vector<int>{ 2, 4, 1, 3, 5 };
  in_place_merge( input.begin(), std::next( input.begin(), 2 ), input.end() );
  auto expected = std::vector<int>{ 1, 2, 3, 4, 5 };
  ASSERT_EQ( input, expected );
}

TEST( in_place_merge, 6_elements_as_if_partially_sorted )
{
  auto input = std::vector<int>{ 1, 6, 7, 2, 5, 8 };
  in_place_merge( input.begin(), std::next( input.begin(), 3 ), input.end() );
  auto expected = std::vector<int>{ 1, 2, 5, 6, 7, 8 };
  ASSERT_EQ( input, expected );
}

TEST( merge_sort_in_place, empty_input )
{
  auto input = std::vector<int>{};
  merge_sort_in_place( input.begin(), input.end() );
  EXPECT_EQ( input.size(), 0 );
}

TEST( merge_sort_in_place, 2_elements_out_of_order )
{
  auto input = std::vector<int>{ 2, 1 };
  merge_sort_in_place( input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2 };
  ASSERT_EQ( input, expected );
}

TEST( merge_sort_in_place, 3_elements_out_of_order )
{
  auto input = std::vector<int>{ 2, 3, 1 };
  merge_sort_in_place( input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2, 3 };
  ASSERT_EQ( input, expected );
}

TEST( merge_sort_in_place, 6_random_elements )
{
  auto input = std::vector<int>{ 7, 6, 1, 2, 8, 5 };
  merge_sort_in_place( input.begin(), input.end() );
  auto expected = std::vector<int>{ 1, 2, 5, 6, 7, 8 };
  ASSERT_EQ( input, expected );
}

TEST( merge_sort_in_place, on_30_element_random_sequence )
{
  auto input = std::vector<int>{ 16, 96, 33, 20, 6,  83, 64, 71, 64, 55, 8,  14, 19, 36, 25,
                                 90, 70, 6,  1,  76, 46, 51, 93, 61, 19, 49, 13, 92, 77, 69 };
  merge_sort_in_place( input.begin(), input.end() );
  auto expected = std::vector<int>{ 1,  6,  6,  8,  13, 14, 16, 19, 19, 20, 25, 33, 36, 46, 49,
                                    51, 55, 61, 64, 64, 69, 70, 71, 76, 77, 83, 90, 92, 93, 96 };
  ASSERT_EQ( input, expected );
}