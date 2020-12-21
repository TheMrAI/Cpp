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
  trie_node( bool is_word = false );

  auto is_word() const -> bool;
  // auto advance_character(char c) const -> const trie_node*;
  // auto remove_character() const ->  const trie_node*;
  bool is_word_;
  std::unordered_map<char, std::unique_ptr<trie_node>> possible_paths_;
};

auto insert_word( trie_node& root_node, const std::string_view word ) -> trie_node&;
auto delete_word_recursively( trie_node& root_node, const std::string_view word ) -> void;
auto words_from_node( std::string current_word, const trie_node& node, std::vector<std::string>& words ) -> void;
auto words_from_node( const trie_node& root_node ) -> std::vector<std::string>;

}  // namespace mrai
#endif  // CONTAINERS_TRIE