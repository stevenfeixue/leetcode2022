/*
 * 1. https://leetcode-cn.com/problems/two-sum/
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> nums_copy;
        int idx = 0;
        for (auto i: nums) {
            nums_copy.push_back(make_pair(i, idx++));
        }

        struct {
           bool operator()(pair<int, int> a, pair<int, int> b) const
           {   
                return a.first < b.first;
           }   
        } customLess;
        sort(nums_copy.begin(),  nums_copy.end(), customLess);

        int i=0;
        int j=nums_copy.size()-1;
        int tmp;
        while ((tmp = (nums_copy[i].first + nums_copy[j].first)) != target) {
            if (tmp > target) {
                --j;
            } else {
                ++i;
            }
        }
        return {nums_copy[i].second, nums_copy[j].second};
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,4};
    int target = 6;
    auto ans = s.twoSum(nums, target);
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
