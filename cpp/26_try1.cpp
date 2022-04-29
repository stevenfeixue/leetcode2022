/*
 * No.26 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * 4 ms    97.46%
 * 17.9 MB 36.56%
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur_elem = 1e8;

        int target = 0;

        for (int p = 0; p != nums.size(); ++p) {
            if (nums[p] != cur_elem) {
                if (p != target) {
                    nums[target] = nums[p];
                    cur_elem = nums[target];
                } else {
                    if (cur_elem == 1e8) cur_elem = nums[p];
                    cur_elem = nums[p];
                }
                target++;
            }
        }
        return target;
    }
};

int main() {
    vector<int> nums {1, 1, 1, 2, 2, 2, 3, 3, 3};
    //vector<int> nums {1, 2, 3, 4, 5, 6 };
    //vector<int> nums {1, 2, 2};
    Solution sl;
    int n = sl.removeDuplicates(nums);
    for (int i=0; i<n; ++i)
        cout << nums[i] << endl;
    return 0;
}
