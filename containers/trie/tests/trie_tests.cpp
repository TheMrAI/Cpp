#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

#include "trie.h"

using namespace mrai;

TEST(insert_word, valid_root_one_character_returns_not_nullptr_word)
{
  auto root = std::make_unique<trie_node>();
  auto& inserted = insert_word(*root, "a");
  EXPECT_TRUE(inserted.is_word());

  auto words = words_from_node(*root);
  EXPECT_EQ(words.size(), 1);
  EXPECT_EQ(words[0], "a");
}

TEST(insert_word, valid_root_whole_word_returns_not_nullptr)
{
  auto root = std::make_unique<trie_node>();
  auto& inserted = insert_word(*root, "potato");
  EXPECT_TRUE(inserted.is_word());

  auto words = words_from_node(*root);
  EXPECT_EQ(words.size(), 1);
  EXPECT_EQ(words[0], "potato");
}

TEST(delete_word_recursively, try_to_delete_from_empty_trie)
{
  auto root = std::make_unique<trie_node>();
  ASSERT_NO_THROW({ delete_word_recursively(*root, "potato"); });
}

TEST(delete_word_recursively, insert_then_delete_word_leaves_empty_root)
{
  auto root = std::make_unique<trie_node>();
  insert_word(*root, "potato");
  delete_word_recursively(*root, "potato");
  ASSERT_TRUE(root->possible_paths_.empty());
}

class trie_node_tests: public ::testing::Test
{
protected:
  trie_node_tests()
  {
    insert_word(*root, "baka");
    insert_word(*root, "aba");
    insert_word(*root, "abot");
    insert_word(*root, "aid");
    insert_word(*root, "braid");
    insert_word(*root, "bra");
    insert_word(*root, "abo");
    insert_word(*root, "ab");
  }

  std::unique_ptr<trie_node> root = std::make_unique<trie_node>();
};

TEST_F(trie_node_tests, list_all_words)
{
  auto words = words_from_node(*root);
  auto expected = std::vector<std::string>{ "aid", "ab",  "abo",   "abot",
                                            "aba", "bra", "braid", "baka" };
  ASSERT_EQ(words, expected);
}

TEST_F(trie_node_tests, delete_baka_braid)
{
  delete_word_recursively(*root, "baka");
  delete_word_recursively(*root, "braid");
  auto words = words_from_node(*root);
  auto expected =
      std::vector<std::string>{ "aid", "ab", "abo", "abot", "aba", "bra" };
  ASSERT_EQ(words, expected);
}

TEST_F(trie_node_tests, delete_inter_trie_words)
{
  delete_word_recursively(*root, "ab");
  delete_word_recursively(*root, "br");
  auto words = words_from_node(*root);
  auto expected = std::vector<std::string>{ "aid", "abo",   "abot", "aba",
                                            "bra", "braid", "baka" };
  ASSERT_EQ(words, expected);
}

TEST_F(trie_node_tests, delete_all_words_expect_baka)
{
  delete_word_recursively(*root, "aba");
  delete_word_recursively(*root, "abot");
  delete_word_recursively(*root, "aid");
  delete_word_recursively(*root, "braid");
  delete_word_recursively(*root, "bra");
  delete_word_recursively(*root, "abo");
  delete_word_recursively(*root, "ab");
  auto words = words_from_node(*root);
  auto expected = std::vector<std::string>{ "baka" };
  ASSERT_EQ(words, expected);
}