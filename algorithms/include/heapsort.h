#ifndef ALGORITHMS_HEAP_SORT
#define ALGORITHMS_HEAP_SPRT

#include <vector>
#include <algorithm>

namespace mrai
{

template<typename T>
auto heapsort(std::vector<T> const & input) -> std::vector<T> 
{
    auto sorted = std::vector<T>(input);
    std::make_heap(sorted.begin(), sorted.end());
    std::sort_heap(sorted.begin(), sorted.end());

    return sorted;
}

}

#endif