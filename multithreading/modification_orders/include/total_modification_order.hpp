#ifndef MULTITHREADING_MODIFICATION_ORDERS_TOTAL_MODIFICATION_ORDER
#define MULTITHREADING_MODIFICATION_ORDERS_TOTAL_MODIFICATION_ORDER

#include <thread>
#include <atomic>

namespace mrai
{
namespace tmo // total modification order
{

inline auto increment_x_times(std::atomic_uint64_t& input, uint32_t increment_count ) -> void
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
    std::atomic_uint64_t value{0};

    auto thread_a = std::thread(increment_x_times, std::ref(value), increment_count);
    auto thread_b = std::thread(increment_x_times, std::ref(value), increment_count);

    thread_a.join();
    thread_b.join();

    return value;
}

} // namespace mrai
} // namespace tmo

#endif // MULTITHREADING_MODIFICATION_ORDERS_TOTAL_MODIFICATION_ORDER