#include <iostream>
#include <functional>
#include "no_total_modification_order.hpp"
#include "total_modification_order.hpp"

auto execute_experiments(std::string const& experiment_name, unsigned experiment_count, unsigned increment_until, std::function<unsigned(unsigned)> experiment_function)
{
    std::cout << "Executing experiment: " << experiment_name << std::endl;
    auto counter = static_cast<uint32_t>(0);
    auto undefined_behaviour_count = static_cast<uint32_t>(0);
    while(counter < experiment_count)
    {
        auto value = experiment_function(increment_until);
        if (value != 2*increment_until)
        {
            ++undefined_behaviour_count;
        }
        ++counter;
    }
    std::cout << "Total tests performed: " << experiment_count << '\n';
    std::cout << "Undefined behaviour encountered: " << undefined_behaviour_count << " times, in percentage: " << (static_cast<double>(undefined_behaviour_count) / static_cast<double>(experiment_count)) * 100 << "%" << '\n';
}

auto main() -> int
{
    std::cout << "Run experiments to see the difference between total modification order and no total modification order." << '\n';
    std::cout << "Thread A and Thread B will each increment the same variable X times." << '\n';
    std::cout << "Expected result will be 2 * X, anything else will be counted as undefined behaviour." << '\n';
    
    auto increment_until = static_cast<uint32_t>(0);
    std::cout << "X: ";
    std::cin >> increment_until;
    std::cout << "Repeat experiments: ";
    auto experiment_count = static_cast<uint32_t>(0);
    std::cin>> experiment_count;

    std::cout << '\n';
    execute_experiments("No total modification order", experiment_count, increment_until, mrai::ntmo::experiment);
    std::cout << '\n';
    execute_experiments("Total modification order", experiment_count, increment_until, mrai::tmo::experiment);

    return 0;
}