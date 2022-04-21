/*
 * No.27 https://leetcode-cn.com/problems/remove-element/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int total = nums.size();
        auto it = nums.begin();
        auto rit = nums.rbegin();
        
        while (it != nums.end() && it != rit.base()) {
            if (*it == val) {
                while (rit.base() != it && *rit == val) {
                    ++rit;
                    --total;
                }
                if (it == rit.base()) return it - nums.begin();
                *it = *rit;
                ++rit;
                --total;
            }
            ++it;
        }
        return total;
    }
};

int main() {
    //vector<int> numbers{ 3, 2, 2, 3};
    vector<int> numbers{ 3, 3, 3, 3, 3};
    Solution sl;
    int n = sl.removeElement(numbers, 3);
    for (int i=0; i<n; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}
