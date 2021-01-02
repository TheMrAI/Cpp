#include <gtest/gtest.h>

#include <vector>

#include "dynamic_programming.h"

using namespace mrai;

TEST(longest_common_subsequence_recursive, empty_inputs)
{
    EXPECT_EQ(longest_common_subsequence_recursive("", "potato"), 0);
    EXPECT_EQ(longest_common_subsequence_recursive("potato", ""), 0);
    EXPECT_EQ(longest_common_subsequence_recursive("", ""), 0);
}

TEST(longest_common_subsequence_recursive, no_common_characters)
{
    ASSERT_EQ(longest_common_subsequence_recursive("aaabbbbcccc", "ddddeeeeffff"), 0);
}

TEST(longest_common_subsequence_recursive, one_common_character)
{
    ASSERT_EQ(longest_common_subsequence_recursive("aaabbbbecccc", "ddddeeeeffff"), 1);
}

TEST(longest_common_subsequence_recursive, DNA_example)
{
    ASSERT_EQ(longest_common_subsequence_recursive("ACCGGTGGAAACCC", "CCTGGGAAAGTACC"), 10);
}

TEST(longest_common_subsequence_recursive, palindrome)
{
    ASSERT_EQ(longest_common_subsequence_recursive("character", "retcarahc"), 5);
}