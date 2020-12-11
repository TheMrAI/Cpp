#ifndef ALGORITHMS_HEAP_SORT
#define ALGORITHMS_HEAP_SORT

#include <vector>
#include <algorithm>

namespace mrai
{

template<typename Iter>
auto heapsort(Iter begin, Iter end) noexcept -> void
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}

template<typename Iter>
auto restore_heap_property_from(Iter begin, Iter end, Iter from) noexcept -> void
{
    auto length = std::distance(begin, end);
    auto index = std::distance(begin, from);
    auto left_child_index = (index * 2) + 1;
    auto right_child_index = left_child_index + 1;

    if (left_child_index < length)
    {
        auto left_child = std::next(begin, left_child_index);
        auto largest = from;
        if (*left_child > *from)
        {
            largest = left_child;
        }
        if (right_child_index < length)
        {
            auto right_child = std::next(left_child, 1);
            if(*right_child > *largest)
            {
                largest = right_child;
            }
        }
        if(largest != from)
        {
            std::iter_swap(largest, from);
            restore_heap_property_from(begin, end, largest);
        }
    }
}

template<typename Iter>
auto manual_make_heap(Iter begin, Iter end) noexcept -> void
{
    if(begin == end)
    {
        return;
    }
    auto length = std::distance(begin, end);
    auto to_step = (length / 2) - 1;
    auto from = std::next(begin, to_step);
    for(auto item = from; item >= begin; --item)
    {
        restore_heap_property_from(begin, end, item);
    }
}

template<typename Iter>
auto manual_sort_heap(Iter begin, Iter end) noexcept -> void
{
    auto last = --end;
    while(begin != last)
    {
        std::iter_swap(begin, last);
        restore_heap_property_from(begin, last, begin);
        --last;
    }
}

template<typename Iter>
auto manual_heapsort(Iter begin, Iter end) noexcept -> void
{
    if(begin == end)
    {
        return;
    }

    manual_make_heap(begin, end);
    manual_sort_heap(begin, end);
}

}

#endif