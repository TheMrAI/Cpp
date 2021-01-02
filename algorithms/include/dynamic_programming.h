#ifndef ALGORITHMS_DYNAMIC_PROGRAMMING
#define ALGORITHMS_DYNAMIC_PROGRAMMING

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace mrai
{
/* Longets common subsequence problem from Chapter 15.4 page 390, Introduction to Algorithms Third Edition by Thomas H.
 * Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein
 */

auto inline lcs_recursive_impl( std::string const& word_a, std::string const& word_b, size_t index_a, size_t index_b )
    -> size_t
{
  if ( index_a == 0 || index_b == 0 )
  {
    return 0;
  }
  if ( word_a[index_a - 1] == word_b[index_b - 1] )
  {
    return 1 + lcs_recursive_impl( word_a, word_b, index_a - 1, index_b - 1 );
  }
  return std::max( lcs_recursive_impl( word_a, word_b, index_a, index_b - 1 ),
                   lcs_recursive_impl( word_a, word_b, index_a - 1, index_b ) );
}

auto inline lcs_recursive( std::string const& word_a, std::string const& word_b ) -> size_t
{
  if ( word_a.empty() || word_b.empty() )
  {
    return 0;
  }
  return lcs_recursive_impl( word_a, word_b, word_a.size(), word_b.size() );
}

auto inline lcs_recursive_impl_with_memoization( std::string const& word_a, std::string const& word_b, size_t index_a,
                                                 size_t index_b, std::vector<std::vector<int>>& memoized ) -> size_t
{
  if ( index_a == 0 || index_b == 0 )
  {
    memoized[index_a][index_b] = 0;
    return 0;
  }
  if ( memoized[index_a][index_b] != -1 )
  {
    return memoized[index_a][index_b];
  }
  if ( word_a[index_a - 1] == word_b[index_b - 1] )
  {
    auto value = 1 + lcs_recursive_impl_with_memoization( word_a, word_b, index_a - 1, index_b - 1, memoized );
    memoized[index_a][index_b] = value;
    return value;
  }
  return std::max( lcs_recursive_impl_with_memoization( word_a, word_b, index_a, index_b - 1, memoized ),
                   lcs_recursive_impl_with_memoization( word_a, word_b, index_a - 1, index_b, memoized ) );
}

auto inline lcs_memoized_recursive( std::string const& word_a, std::string const& word_b ) -> size_t
{
  if ( word_a.empty() || word_b.empty() )
  {
    return 0;
  }
  auto memoized = std::vector<std::vector<int>>( word_a.size() + 1, std::vector<int>( word_b.size() + 1, -1 ) );
  return lcs_recursive_impl_with_memoization( word_a, word_b, word_a.size(), word_b.size(), memoized );
}

auto inline lcs_dp_bottom_up( std::string const& word_a, std::string const& word_b ) -> std::vector<std::vector<size_t>>
{
  auto dp = std::vector<std::vector<size_t>>( word_a.size() + 1, std::vector<size_t>( word_b.size() + 1, 0 ) );
  if ( word_a.empty() || word_b.empty() )
  {
    return dp;
  }

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

  return dp;
}

auto inline get_lcs( std::string const& word_a, std::string const& word_b,
                     std::vector<std::vector<size_t>> const& memoized ) -> std::string
{
  auto longest_common_subsequence = std::string{};

  auto i = word_a.size();
  auto j = word_b.size();
  while ( i != 0 && j != 0 )
  {
    if ( word_a[i - 1] == word_b[j - 1] )
    {
      longest_common_subsequence.push_back( word_a[i - 1] );
      --i;
      --j;
    }
    else if ( memoized[i - 1][j] > memoized[i][j - 1] )
    {
      --i;
    }
    else
    {
      --j;
    }
  }

  std::reverse( longest_common_subsequence.begin(), longest_common_subsequence.end() );
  return longest_common_subsequence;
}

}  // namespace mrai

#endif