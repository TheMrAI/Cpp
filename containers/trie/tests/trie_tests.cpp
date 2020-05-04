#include <gtest/gtest.h>

#include <memory>

#include "trie.h"

using namespace mrai;

TEST(insert_word, valid_root_one_character_returns_not_nullptr_word)
{
  auto root = std::make_unique<trie_node>();
  auto& inserted = insert_word(*root.get(), "a");
  EXPECT_TRUE(inserted.is_word());

  auto words = words_from_node(*root.get());
  EXPECT_EQ(words.size(), 1);
  EXPECT_EQ(words[0], "a");
}

TEST(insert_word, valid_root_whole_word_returns_not_nullptr)
{
  auto root = std::make_unique<trie_node>();
  auto& inserted = insert_word(*root.get(), "potato");
  EXPECT_TRUE(inserted.is_word());

  auto words = words_from_node(*root.get());
  EXPECT_EQ(words.size(), 1);
  EXPECT_EQ(words[0], "potato");
}