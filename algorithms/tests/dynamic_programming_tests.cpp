#include <gtest/gtest.h>

#include <vector>

#include "dynamic_programming.h"

using namespace mrai;

TEST( lcs_recursive, empty_inputs )
{
  EXPECT_EQ( lcs_recursive( "", "potato" ), 0 );
  EXPECT_EQ( lcs_recursive( "potato", "" ), 0 );
  EXPECT_EQ( lcs_recursive( "", "" ), 0 );
}

TEST( lcs_recursive, no_common_characters )
{
  ASSERT_EQ( lcs_recursive( "aaabbbbcccc", "ddddeeeeffff" ), 0 );
}

TEST( lcs_recursive, one_common_character )
{
  ASSERT_EQ( lcs_recursive( "aaabbbbecccc", "ddddeeeeffff" ), 1 );
}

TEST( lcs_recursive, DNA_example )
{
  ASSERT_EQ( lcs_recursive( "ACCGGTGGAAACCC", "CCTGGGAAAGTACC" ), 10 );
}

TEST( lcs_recursive, palindrome )
{
  ASSERT_EQ( lcs_recursive( "character", "retcarahc" ), 5 );
}

TEST( lcs_memoized_recursive, empty_inputs )
{
  EXPECT_EQ( lcs_memoized_recursive( "", "potato" ), 0 );
  EXPECT_EQ( lcs_memoized_recursive( "potato", "" ), 0 );
  EXPECT_EQ( lcs_memoized_recursive( "", "" ), 0 );
}

TEST( lcs_memoized_recursive, no_common_characters )
{
  ASSERT_EQ( lcs_memoized_recursive( "aaabbbbcccc", "ddddeeeeffff" ), 0 );
}

TEST( lcs_memoized_recursive, one_common_character )
{
  ASSERT_EQ( lcs_memoized_recursive( "aaabbbbecccc", "ddddeeeeffff" ), 1 );
}

TEST( lcs_memoized_recursive, DNA_example )
{
  ASSERT_EQ( lcs_memoized_recursive( "ACCGGTGGAAACCC", "CCTGGGAAAGTACC" ), 10 );
}

TEST( lcs_memoized_recursive, palindrome )
{
  ASSERT_EQ( lcs_memoized_recursive( "character", "retcarahc" ), 5 );
}

TEST( lcs_dp_bottom_up, empty_inputs )
{
  EXPECT_EQ( lcs_dp_bottom_up( "", "potato" )[0][6], 0 );
  EXPECT_EQ( lcs_dp_bottom_up( "potato", "" )[6][0], 0 );
  EXPECT_EQ( lcs_dp_bottom_up( "", "" )[0][0], 0 );
}

TEST( lcs_dp_bottom_up, no_common_characters )
{
  auto word_a = std::string( "aaabbbbcccc" );
  auto word_b = std::string( "ddddeeeeffff" );
  auto result = lcs_dp_bottom_up( word_a, word_b );
  ASSERT_EQ( result[11][12], 0 );
  // ASSERT_EQ( get_lcs( word_a, word_b, result ), "" );
}

TEST( lcs_dp_bottom_up, one_common_character )
{
  auto word_a = std::string( "aaabbbbecccc" );
  auto word_b = std::string( "ddddeeeeffff" );
  auto result = lcs_dp_bottom_up( word_a, word_b );
  ASSERT_EQ( result[12][12], 1 );
  ASSERT_EQ( get_lcs( word_a, word_b, result ), "e" );
}

TEST( lcs_dp_bottom_up, DNA_example )
{
  auto word_a = std::string( "ACCGGTGGAAACCC" );
  auto word_b = std::string( "CCTGGGAAAGTACC" );
  auto result = lcs_dp_bottom_up( word_a, word_b );
  ASSERT_EQ( result[14][14], 10 );
  ASSERT_EQ( get_lcs( word_a, word_b, result ), "CCTGGAAACC" );  // also correct "CCGGGAAACC"
}

TEST( lcs_dp_bottom_up, palindrome )
{
  auto word_a = std::string( "character" );
  auto word_b = std::string( "retcarahc" );
  auto result = lcs_dp_bottom_up( word_a, word_b );
  ASSERT_EQ( result[9][9], 5 );
  ASSERT_EQ( get_lcs( word_a, word_b, result ), "carac" );
}