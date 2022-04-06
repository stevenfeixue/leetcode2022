/*
 * 66: https://leetcode-cn.com/problems/plus-one/
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int val = 1;
        for (auto it=digits.rbegin(); it != digits.rend(); ++it) {
            *it = *it + val;
            if ((*it % 10)) {
               val = 0;
            } else {
               *it = 0;
            }
        }
        if (val) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution sl;
    vector<int> digits({1,9,1,9});
    auto res = sl.plusOne(digits);
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
