#include <gtest/gtest.h>

#include "trie.h"

using namespace mrai;

class default_constructed_trie: public ::testing::Test
{
protected:
  default_constructed_trie()
  {
  }

  trie empty_trie;
};

TEST_F(default_constructed_trie, insert_empty_string)
{
  ASSERT_EQ(empty_trie.insert(""), nullptr);
}

TEST_F(default_constructed_trie, insert_one_character)
{
  auto* node = empty_trie.insert("a");
  EXPECT_NE(node, nullptr);
  EXPECT_TRUE(node->is_word());
}

TEST_F(default_constructed_trie, insert_multiple_words)
{
  auto* banana = empty_trie.insert("banana");
  EXPECT_NE(banana, nullptr);
  EXPECT_TRUE(banana->is_word());

  auto* backlava = empty_trie.insert("backlava");
  EXPECT_NE(backlava, nullptr);
  EXPECT_TRUE(backlava->is_word());

  auto* baba = empty_trie.insert("baba");
  EXPECT_NE(baba, nullptr);
  EXPECT_TRUE(baba->is_word());
}

TEST_F(default_constructed_trie,
       list_possibilities_empty_string_returns_nothing)
{
  auto possibilities = empty_trie.list_possibilities("");
  ASSERT_EQ(possibilities.size(), 0);
}

TEST_F(default_constructed_trie,
       list_possibilities_proper_value_returns_nothing)
{
  auto possibilities = empty_trie.list_possibilities("potato");
  ASSERT_EQ(possibilities.size(), 0);
}

class loaded_trie: public ::testing::Test
{
protected:
  loaded_trie()
  {
    data.insert("aba");
    data.insert("abacus");
    data.insert("bloat");
    data.insert("bagamon");
    data.insert("helicopter");
    data.insert("bag");
  }

  trie data;
};

TEST_F(loaded_trie, find_all_words)
{
  EXPECT_NE(data.find("aba"), nullptr);
  EXPECT_NE(data.find("abacus"), nullptr);
  EXPECT_NE(data.find("bloat"), nullptr);
  EXPECT_NE(data.find("bagamon"), nullptr);
  EXPECT_NE(data.find("helicopter"), nullptr);
  EXPECT_NE(data.find("bag"), nullptr);
}