#include "trie.h"

#include <memory>
#include <unordered_map>

namespace mrai
{
trie_node::trie_node(bool is_word): is_word_{ is_word }
{
}

trie::trie(): root_{ std::make_unique<trie_node>() }
{
}

auto trie::insert(const std::string& word) -> void
{
  auto* walker = root_.get();
  for (const auto& character : word)
  {
    if (walker->possible_paths_.count(character) == 0)
    {
      walker->possible_paths_[character] = std::make_unique<trie_node>();
    }
    walker = walker->possible_paths_[character].get();
  }
  walker->is_word_ = true;
}

auto trie::is_word(const std::string& word) const -> bool
{
  auto* walker = root_.get();
  for (const auto& character : word)
  {
    if (walker->possible_paths_.count(character) == 0)
    {
      return false;
    }
    walker = walker->possible_paths_[character].get();
  }
  return walker->is_word_;
}

auto trie::list_possibilities(const std::string& word)
    -> std::vector<std::string>
{
  std::vector<std::string> possibilities;
  auto* walker = root_.get();
  for (const auto& character : word)
  {
    if (walker->possible_paths_.count(character) == 0)
    {
      walker->possible_paths_[character] = std::make_unique<trie_node>();
    }
    walker = walker->possible_paths_[character].get();
  }
  collect_options(walker, word, possibilities);

  return possibilities;
}

auto trie::collect_options(trie_node* walker, std::string word,
                           std::vector<std::string>& possibilities) const
    -> void
{
  if (walker->is_word_)
  {
    possibilities.push_back(word);
  }
  if (walker->possible_paths_.empty())
  {
    return;
  }
  for (const auto& entries : walker->possible_paths_)
  {
    collect_options(entries.second.get(), word + entries.first, possibilities);
  }
}

/*auto trie::delete(const std::string& word) -> void
{

}*/

}  // namespace mrai