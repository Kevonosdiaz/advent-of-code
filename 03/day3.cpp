#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::string tmp;
    while(std::cin >> tmp)
    {
        input.append(tmp);
    }

    // Create regex to capture each of the two ints in pattern
    const std::regex base_pattern("mul\\(([0-9]+),([0-9]+)\\)"); // mul([any int],[any int]);
    auto             match_begin = std::sregex_iterator(input.begin(), input.end(), base_pattern);
    auto             match_end   = std::sregex_iterator();

    int x1;
    int x2;
    int sum = 0;

    for(auto it = match_begin; it != match_end; ++it)
    {
        std::smatch match = *it;
        // Grab from each capture group; idx 0 is entire match so start at 1
        x1 = std::stoi(match.str(1));
        x2 = std::stoi(match.str(2));
        sum += x1 * x2;
    }

    std::cout << sum << std::endl;

    /* Part 2 */
    const std::regex mul_or_condition_pattern("mul\\(([0-9]+),([0-9]+)\\)|do\\(\\)|don't\\(\\)");
    auto match2_begin = std::sregex_iterator(input.begin(), input.end(), mul_or_condition_pattern);
    auto match2_end   = std::sregex_iterator();

    int y1;
    int y2;
    sum = 0;

    bool do = true;

    for(auto it = match2_begin; it != match2_end; ++it)
    {
        std::smatch match = *it;
        // First check which pattern it matched

        // Grab from each capture group; idx 0 is entire match so start at 1
        if(do)
        {
            y1 = std::stoi(match.str(1));
            y2 = std::stoi(match.str(2));
            sum += y1 * y2;
        }
    }

    std::cout << sum << std::endl;
    return sum;
}
