#ifndef CONTAINERS_TRIE
#define CONTAINERS_TRIE

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace mrai
{
class trie;

class trie_node
{
public:
  trie_node(trie_node* parrent = nullptr, bool is_word = false);

  auto is_word() const -> bool;
  // auto advance_character(char c) const -> const trie_node*;
  // auto remove_character() const ->  const trie_node*;
private:
  trie_node* parrent_;
  bool is_word_;
  std::unordered_map<char, std::unique_ptr<trie_node>> possible_paths_;

  friend trie;
};

class trie
{
public:
  trie();

  auto insert(const std::string& word) -> const trie_node*;
  auto find(const std::string& word) -> trie_node*;
  // auto delete(const std::string& word) -> void;
  auto list_possibilities(const std::string& word) -> std::vector<std::string>;
  /*auto list_possibilities(const trie_node* node) -> std::vector<std::string>;
  auto delete(trie_node* node) -> void;
  */
private:
  auto collect_options(trie_node* walker, std::string word,
                       std::vector<std::string>& possibilities) const -> void;

  std::unique_ptr<trie_node> root_;
};

}  // namespace mrai
#endif  // CONTAINERS_TRIE