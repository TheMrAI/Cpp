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
  trie_node(bool is_word = false);

private:
  bool is_word_;
  std::unordered_map<char, std::unique_ptr<trie_node>> possible_paths_;

  friend trie;
};

class trie
{
public:
  trie();

  auto insert(const std::string& word) -> void;
  auto list_possibilities(const std::string& word) -> std::vector<std::string>;
  // auto delete(const std::string& word) -> void;

  auto is_word(const std::string& word) const -> bool;

private:
  auto collect_options(trie_node* walker, std::string word,
                       std::vector<std::string>& possibilities) const -> void;

  std::unique_ptr<trie_node> root_;
};

}  // namespace mrai
#endif  // CONTAINERS_TRIE