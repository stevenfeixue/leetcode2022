/*
 * No.27 https://leetcode-cn.com/problems/remove-element/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int n = 0;
        vector<int>::iterator left, right;
        left = right = nums.begin();
        while (right != nums.end()) {

            if (*right != val) {
                *left++ = *right;
                 n++;
            } 
            right++;
        }
        return n;
    }
};

int main() {
    vector<int> numbers{ 0, 1, 2, 2, 3, 0, 4, 2};
    Solution sl;
    int n = sl.removeElement(numbers, 2);
    for (int i=0; i<n; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}
