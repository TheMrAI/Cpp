#include "trie.h"

#include <memory>
#include <unordered_map>

namespace mrai
{
trie_node::trie_node(trie_node* parrent, bool is_word)
    : parrent_{ parrent }, is_word_{ is_word }
{
}

auto trie_node::is_word() const -> bool
{
  return is_word_;
}

auto insert_word(trie_node& root_node, const std::string& word) -> trie_node&
{
  auto* walker = &root_node;
  for (const auto& character : word)
  {
    if (walker->possible_paths_.count(character) == 0)
    {
      walker->possible_paths_[character] =
          std::make_unique<trie_node>(walker, false);
    }
    walker = walker->possible_paths_[character].get();
  }
  walker->is_word_ = true;
  return *walker;
}

auto words_from_node(std::string current_word, const trie_node& node,
                     std::vector<std::string>& words) -> void
{
  if (node.is_word())
  {
    words.push_back(current_word);
  }
  for (const auto& entry : node.possible_paths_)
  {
    words_from_node(current_word + entry.first, *entry.second.get(), words);
  }
}

auto words_from_node(const trie_node& root_node) -> std::vector<std::string>
{
  auto words = std::vector<std::string>{};
  for (const auto& entry : root_node.possible_paths_)
  {
    words_from_node(std::string(1, entry.first), *entry.second.get(), words);
  }
  return words;
}

}  // namespace mrai