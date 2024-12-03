#include <iostream>
#include <vector>
#include <algorithm>

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

    // Sum up absolute element-wise difference
    int res = 0;
    for(size_t i = 0; i < list1.size(); i++) {
        res += std::abs(list1[i] - list2[i]);
    }

    std::cout << "Output is: " << res << std::endl;
    return res;
}
