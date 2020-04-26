#include <gtest/gtest.h>

#include "trie.h"

using namespace mrai;

TEST(trie, insert_a_one_character_word)
{
  trie data;
  data.insert("c");
  ASSERT_TRUE(data.is_word("c"));
}

TEST(trie, insert_one_word_searching_for_another_gives_nothing)
{
  trie data;
  data.insert("potato");
  ASSERT_FALSE(data.is_word("cabbage"));
}

TEST(trie, insert_one_word_searching_for_subword_inst_a_word)
{
  trie data;
  data.insert("helicopter");
  ASSERT_FALSE(data.is_word("heli"));
}

TEST(trie, one_word_list_possibilities_returns_it)
{
  trie data;
  data.insert("helicopter");
  auto possibilities = data.list_possibilities("heli");
  EXPECT_EQ(possibilities.size(), 1);
  EXPECT_EQ(possibilities[0], "helicopter");
}
