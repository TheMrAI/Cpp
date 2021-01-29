#ifndef MULTITHREADING_MODIFICATION_ORDERS_NO_TOTAL_MODIFICATION_ORDER
#define MULTITHREADING_MODIFICATION_ORDERS_NO_TOTAL_MODIFICATION_ORDER

#include <thread>

namespace mrai
{
namespace ntmo // no total modification order
{

inline auto increment_x_times(uint64_t& input, uint32_t increment_count ) -> void
{
    auto count = 0U;
    while(count < increment_count)
    {
        ++input;
        ++count;
    }
}

inline auto experiment(uint32_t increment_count) -> uint64_t
{
    auto value = static_cast<uint64_t>(0);

    auto thread_a = std::thread(increment_x_times, std::ref(value), increment_count);
    auto thread_b = std::thread(increment_x_times, std::ref(value), increment_count);

    thread_a.join();
    thread_b.join();

    return value;
}

} // namespace ntmo
} // namespace mrai

#endif // MULTITHREADING_MODIFICATION_ORDERS_NO_TOTAL_MODIFICATION_ORDER