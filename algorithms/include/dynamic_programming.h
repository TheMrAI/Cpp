#ifndef ALGORITHMS_DYNAMIC_PROGRAMMING
#define ALGORITHMS_DYNAMIC_PROGRAMMING

namespace mrai
{

/* Longets common subsequence problem from Chapter 15.4 page 390, Introduction to Algorithms Third Edition by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein */

auto longest_common_subsequence_recursive_impl(std::string const& word_a, std::string const& word_b, size_t index_a, size_t index_b)
{
    if(index_a == 0 || index_b == 0)
    {
        return 0;
    }
    if(word_a[index_a - 1] == word_b[index_b - 1])
    {
        return 1 + longest_common_subsequence_recursive_impl(word_a, word_b, index_a - 1, index_b-1);
    }
    return std::max(longest_common_subsequence_recursive_impl(word_a, word_b, index_a, index_b-1), longest_common_subsequence_recursive_impl(word_a, word_b, index_a - 1, index_b));
}

auto longest_common_subsequence_recursive(std::string const& word_a, std::string const& word_b)
{
    if(word_a.empty() || word_b.empty())
    {
        return 0;
    }
    return longest_common_subsequence_recursive_impl(word_a, word_b, word_a.size(), word_b.size());
}



/*
Problem: Give an algorithm that finds the longest palindromic subsequence for a given input string.
Input: character
Ouptut: carac
*/

}

#endif