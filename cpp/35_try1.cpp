/*
 * No.35 https://leetcode.cn/problems/search-insert-position/
 * 8ms 8.76%
 * 9.4MB 68.30%
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (target < nums[0]) return 0;
        if (target > nums[size-1]) return size;
        int start = 0, end = size - 1;
        int i = (start + end)/2;
        while (target != nums[i]) {
           if (target > nums[i]) {
               start = i;
           } else {
               end = i;
           }
           if (i == (start + end) / 2) break;
           else i = (start + end)/2;
        }
        if (target > nums[i]) return i+1;
        else return i;
    }
};

int main() {
    Solution sl;
    vector<int>  nums{1,3,9,40,70,72,100};
    cout << sl.searchInsert(nums, 0) << endl;
    cout << sl.searchInsert(nums, 2) << endl;
    cout << sl.searchInsert(nums, 5) << endl;
    cout << sl.searchInsert(nums, 10) << endl;
    cout << sl.searchInsert(nums, 41) << endl;
    cout << sl.searchInsert(nums, 71) << endl;
    cout << sl.searchInsert(nums, 99) << endl;
    cout << sl.searchInsert(nums, 101) << endl;
    cout << sl.searchInsert(nums, 1) << endl;
    cout << sl.searchInsert(nums, 3) << endl;
    cout << sl.searchInsert(nums, 9) << endl;
    cout << sl.searchInsert(nums, 40) << endl;
    cout << sl.searchInsert(nums, 70) << endl;
    cout << sl.searchInsert(nums, 72) << endl;
    cout << sl.searchInsert(nums, 100) << endl;
    return 0;
}
