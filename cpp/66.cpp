/*
 * 66: https://leetcode-cn.com/problems/plus-one/
 */
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        deque<int> tmp(digits.begin(), digits.end());
        int val = 1;
        for (auto it=tmp.rbegin(); it != tmp.rend(); ++it) {
            *it = *it + val;
            if ((*it % 10)) {
               val = 0;
            } else {
               *it = 0;
            }
        }
        if (val) {
            tmp.push_front(1);
        }
        result.reserve(tmp.size() + val);
        copy(tmp.cbegin(), tmp.cend(), back_inserter(result));
        return result;
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
