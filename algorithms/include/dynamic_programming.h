#ifndef ALGORITHMS_DYNAMIC_PROGRAMMING
#define ALGORITHMS_DYNAMIC_PROGRAMMING

#include <string>
#include <vector>

namespace mrai
{
/* Longets common subsequence problem from Chapter 15.4 page 390, Introduction to Algorithms Third Edition by Thomas H.
 * Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein */

auto inline longest_common_subsequence_recursive_impl( std::string const& word_a, std::string const& word_b,
                                                       size_t index_a, size_t index_b ) -> size_t
{
  if ( index_a == 0 || index_b == 0 )
  {
    return 0;
  }
  if ( word_a[index_a - 1] == word_b[index_b - 1] )
  {
    return 1 + longest_common_subsequence_recursive_impl( word_a, word_b, index_a - 1, index_b - 1 );
  }
  return std::max( longest_common_subsequence_recursive_impl( word_a, word_b, index_a, index_b - 1 ),
                   longest_common_subsequence_recursive_impl( word_a, word_b, index_a - 1, index_b ) );
}

auto inline longest_common_subsequence_recursive( std::string const& word_a, std::string const& word_b ) -> size_t
{
  if ( word_a.empty() || word_b.empty() )
  {
    return 0;
  }
  return longest_common_subsequence_recursive_impl( word_a, word_b, word_a.size(), word_b.size() );
}

auto inline longest_common_subsequence_dynamic_programming_bottom_up( std::string const& word_a,
                                                                      std::string const& word_b ) -> size_t
{
  if ( word_a.empty() || word_b.empty() )
  {
    return 0;
  }
  auto dp = std::vector<std::vector<size_t>>( word_a.size() + 1, std::vector<size_t>( word_b.size() + 1, 0 ) );

  for ( size_t i = 0; i < word_a.size(); ++i )
  {
    for ( size_t j = 0; j < word_b.size(); ++j )
    {
      if ( word_a[i] == word_b[j] )
      {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else
      {
        dp[i + 1][j + 1] = std::max( dp[i + 1][j], dp[i][j + 1] );
      }
    }
  }

  return dp[word_a.size()][word_b.size()];
}

/*
Problem: Give an algorithm that finds the longest palindromic subsequence for a given input string.
Input: character
Ouptut: carac
*/

}  // namespace mrai

#endif