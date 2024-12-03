#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

// Check for either increasing/decreasing pattern, and change between 1-3
// (inclusive)
bool isSafe(std::vector<int>& v)
{
    // Assume at least 2 elements (input has at least 5 per line)
    bool ascending = v[0] < v[1];
    for(size_t i = 1; i < v.size(); i++)
    {
        int diff = std::abs(v[i - 1] - v[i]);
        if(ascending != v[i - 1] < v[i] || diff < 1 || diff > 3)
            return false;
    }
    return true;
}

int main()
{
    // Read in input lines of varying length
    std::vector<std::vector<int>> reports;
    std::string                   tmp_line;
    while(std::getline(std::cin, tmp_line))
    {
        std::istringstream ss(tmp_line);
        std::vector<int>   report;
        int                tmp_int;
        while(ss >> tmp_int)
            report.push_back(tmp_int);
        reports.push_back(report);
    }

    int num_safe_reports = 0;
    for(auto& r : reports)
        num_safe_reports += isSafe(r);

    std::cout << num_safe_reports << std::endl;

    num_safe_reports = 0;
    for(auto& report : reports)
    {

        for(size_t i = 0; i < report.size(); i++)
        {
            auto             l = std::vector<int>(report.begin(), report.begin() + i);
            auto             r = std::vector<int>(report.begin() + i + 1, report.end());
            std::vector<int> input;
            input.reserve(report.size() - 1);
            input.insert(input.end(), l.begin(), l.end());
            input.insert(input.end(), r.begin(), r.end());
            bool safe = isSafe(input);
            if(safe)
            {
                num_safe_reports++;
                break;
            }
        }
    }
    std::cout << num_safe_reports << std::endl;
    return num_safe_reports;
}
