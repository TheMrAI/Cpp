#include "trie.h"

#include <memory>
#include <unordered_map>

namespace mrai
{
trie_node::trie_node( bool is_word ): is_word_{ is_word }
{}

auto trie_node::is_word() const -> bool
{
  return is_word_;
}

auto insert_word( trie_node& root_node, std::string_view const word ) -> trie_node&
{
  auto* walker = &root_node;
  for ( const auto& character : word )
  {
    if ( walker->possible_paths_.count( character ) == 0 )
    {
      walker->possible_paths_[character] = std::make_unique<trie_node>( false );
    }
    walker = walker->possible_paths_[character].get();
  }
  walker->is_word_ = true;
  return *walker;
}

auto delete_word_recursively( trie_node& root_node, std::string_view const word ) -> void
{
  if ( word.empty() )
  {
    return;
  }
  auto character = word[0];
  if ( root_node.possible_paths_.count( character ) == 0U )
  {
    return;
  }

  auto& child_node = root_node.possible_paths_[character];
  if ( word.size() == 1 )
  {
    child_node->is_word_ = false;
    if ( child_node->possible_paths_.empty() )
    {
      root_node.possible_paths_.erase( character );
    }
    return;
  }

  delete_word_recursively( *child_node, std::string_view{ word.data() + 1, word.size() - 1 } );

  if ( child_node->possible_paths_.empty() && !child_node->is_word() )
  {
    root_node.possible_paths_.erase( character );
  }
}

auto words_from_node( std::string const& current_word, trie_node const& node, std::vector<std::string>& words ) -> void
{
  if ( node.is_word() )
  {
    words.push_back( current_word );
  }
  for ( const auto& entry : node.possible_paths_ )
  {
    words_from_node( current_word + entry.first, *entry.second, words );
  }
}

auto words_from_node( trie_node const& root_node ) -> std::vector<std::string>
{
  auto words = std::vector<std::string>{};
  for ( auto const& entry : root_node.possible_paths_ )
  {
    words_from_node( std::string( 1, entry.first ), *entry.second, words );
  }
  return words;
}

}  // namespace mrai