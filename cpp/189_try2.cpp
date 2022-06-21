#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (!(k % size)) return;
        else k = k % size;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


int main() {
    Solution sl;
    vector<int>  data{1,2,3,4,5,6,7,8,9,10};
    sl.rotate(data, 5);
    for (auto i: data)
        cout << i << " ";
    cout << "\n";
    return 0;
}
