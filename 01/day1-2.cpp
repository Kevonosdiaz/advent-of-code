#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    // Read in input via stdin
    std::vector<int> list1;
    std::vector<int> list2;
    int tmp1;
    int tmp2;

    while(std::cin >> tmp1 >> tmp2) {
        list1.push_back(tmp1);
        list2.push_back(tmp2);
    }

    // Sort each to allow for matching up ascending pairs
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    std::unordered_map<int, int> num_freqs2;

    // Store frequency of elements found in the right list
    for(size_t i = 0; i < list1.size(); i++) {
        num_freqs2[list2[i]]++;
    }

    // Sum up similarity score (val * # of occurrences in right list)
    int res = 0;
    for(auto v : list1) {
        res += v * num_freqs2[v];
    }

    std::cout << "Output is: " << res << std::endl;
    return res;
}
