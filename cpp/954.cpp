/*
 * 954: https://leetcode-cn.com/problems/array-of-doubled-pairs/
 */
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        std::multiset<int> data(arr.begin(), arr.end());

        auto zero_count = data.count(0);
        if (zero_count % 2) return false;

        for (auto it = data.begin(); it != data.end(); /* */) {
            multiset<int>::iterator  search;
            if (*it > 0) {
                search = data.find(2**it);
            } else if (*it == 0) {
                it++;
                continue;
            } else {
                if (*it % 2)  return false;
                search = data.find(*it/2);
            }

            if (search == data.end()) {
                return false;
            } else {
                data.erase(search);
                it++;
            }
        }
        return true;
    }
};

int main() {
    Solution sl;
    std::vector<int> arr{-4, 3, 1, 2, -1, 6, -2, -2};
    std::multiset<int> myset(arr.begin(), arr.end());

    auto ret = sl.canReorderDoubled(arr);
    if (ret)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}
