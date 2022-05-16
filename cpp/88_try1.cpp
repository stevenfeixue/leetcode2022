/*
 * No.88 https://leetcode-cn.com/problems/merge-sorted-array/
 * 0ms 100%
 * 8.8MB 66.55%
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = std::move(nums2);
            return;
        }

        int i = 0, j = 0, k = 0;
        int total_index = 0;
        vector<int> nums3(nums1.begin(), nums1.begin() + m);


        while (i<n && j<m) {
             if (nums2[i] <= nums3[j]) {
                 nums1[total_index++] = nums2[i++]; 
                 
             } else {
                 nums1[total_index++] = nums3[j++];
             }
        }
        if (j == m) {
            while (total_index < m + n) {
                nums1[total_index++] = nums2[i++];
            }
        } else {
            while (total_index < m + n) {
                nums1[total_index++] = nums3[j++];
            }
        }

        
    }
};

int main() {
    vector<int> nums1{1,3,4,18,0,0,0};
    vector<int> nums2{2,5,6};
    Solution sl;
    sl.merge(nums1, 4, nums2, 3);
    for (auto i: nums1) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
