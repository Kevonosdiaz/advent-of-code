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

    const std::regex base_pattern("mul\\(([0-9]+),([0-9]+)\\)"); // mul([any number],[any number]);
    auto             match_begin = std::sregex_iterator(input.begin(), input.end(), base_pattern);
    auto             match_end   = std::sregex_iterator();

    int x1;
    int x2;
    int sum;

    for(auto it = match_begin; it != match_end; ++it)
    {
        std::smatch match = *it;
        x1                = std::stoi(match.str(1));
        x2                = std::stoi(match.str(2));
        sum += x1 * x2;
    }

    std::cout << sum << std::endl;
    return sum;
}
