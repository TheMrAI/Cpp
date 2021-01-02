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

TEST( lcs_dp_bottom_up, empty_inputs )
{
  EXPECT_EQ( lcs_dp_bottom_up( "", "potato" ), 0 );
  EXPECT_EQ( lcs_dp_bottom_up( "potato", "" ), 0 );
  EXPECT_EQ( lcs_dp_bottom_up( "", "" ), 0 );
}

TEST( lcs_dp_bottom_up, no_common_characters )
{
  ASSERT_EQ( lcs_dp_bottom_up( "aaabbbbcccc", "ddddeeeeffff" ), 0 );
}

TEST( lcs_dp_bottom_up, one_common_character )
{
  ASSERT_EQ( lcs_dp_bottom_up( "aaabbbbecccc", "ddddeeeeffff" ), 1 );
}

TEST( lcs_dp_bottom_up, DNA_example )
{
  ASSERT_EQ( lcs_dp_bottom_up( "ACCGGTGGAAACCC", "CCTGGGAAAGTACC" ), 10 );
}

TEST( lcs_dp_bottom_up, palindrome )
{
  ASSERT_EQ( lcs_dp_bottom_up( "character", "retcarahc" ), 5 );
}