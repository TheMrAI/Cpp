#ifndef CONTAINERS_TRIE
#define CONTAINERS_TRIE

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace mrai
{
class trie;

class trie_node
{
public:
  explicit trie_node( bool is_word = false );

  auto is_word() const -> bool;
  // auto advance_character(char c) const -> const trie_node*;
  // auto remove_character() const ->  const trie_node*;

  bool is_word_;                                                         // NOLINT
  std::unordered_map<char, std::unique_ptr<trie_node>> possible_paths_;  // NOLINT
};

auto insert_word( trie_node& root_node, std::string_view word ) -> trie_node&;
auto delete_word_recursively( trie_node& root_node, std::string_view word ) -> void;
auto words_from_node( std::string const& current_word, trie_node const& node, std::vector<std::string>& words ) -> void;
auto words_from_node( trie_node const& root_node ) -> std::vector<std::string>;

}  // namespace mrai
#endif  // CONTAINERS_TRIE