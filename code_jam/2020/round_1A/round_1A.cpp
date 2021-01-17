#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

auto patterns_match(std::string const& master, std::string const& pattern) -> std::pair<bool, std::string>
{
    return std::make_pair(true, master);
}

auto pattern_match_result(std::string const& input, std::vector<std::string>& patterns) -> std::string
{
    std::sort(patterns.begin(), patterns.end(), [](auto const& lhs, auto const& rhs)
    {
        return lhs.size() > rhs.size();
    });

    auto master_pattern = patterns[0];
    auto valid = true;
    auto pattern_index = static_cast<size_t>(1);
    while(valid && pattern_index < patterns.size())
    {
        std::tie(valid, master_pattern) = patterns_match(master_pattern, patterns[pattern_index]);
        ++pattern_index;
    }
    
    return master_pattern;
}

int main() 
{
    auto test_count = 0;
    std::cin >> test_count;
    for (int i = 1; i <= test_count; ++i) 
    {
        auto number_of_patterns = 0;
        auto patterns = std::vector<std::string>{};

        std::cin >> number_of_patterns;
        while(number_of_patterns > 0)
        {
            auto pattern = std::string{};
            std::cin >> pattern;
            patterns.push_back(pattern);
        }
        std::cout << "Case #" << i << ": " << std::endl;
    }
    return 0;
}