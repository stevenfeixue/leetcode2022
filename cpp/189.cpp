#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy;
        int size = nums.size();
        if (!(k % size)) return;
        else k = k % size;
        
        copy.insert(copy.end(), nums.begin() + size - k, nums.end());
        copy.insert(copy.end(), nums.begin(), nums.begin() + size - k);
        nums = copy;
    }
};

int main() {
    Solution sl;
    vector<int>  data{-1};
    sl.rotate(data, 2);
    for (auto i: data)
        cout << i << " ";
    cout << "\n";
    return 0;
}
