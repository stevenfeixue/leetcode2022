/*
 * 307: https://leetcode-cn.com/problems/range-sum-query-mutable/
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums): num_array(nums) {
        auto size = num_array.size();
        vector<int> tmp(size, 0);
        diff = std::move(tmp);
    }
    
    void update(int index, int val) {
        int old = num_array[index];
        num_array[index] = val;
        diff[index] = val - old;
    }
    
    int sumRange(int left, int right) {
        int sum{0};
        map<pair<int, int>, int>::iterator it;
        auto key = make_pair(left, right);

        if ((it = rangeSumMap.find(key)) == rangeSumMap.end()) {
            for (int i = left; i <= right; ++i) {
                sum += num_array[i];
            }
            rangeSumMap[key] = sum;
            
            for (int i = left; i <= right; ++i) {
                diff[i] = 0;
            }
        } else {
            for (int i = left; i <= right; ++i) {
                rangeSumMap[key] += diff[i];
            }
        }
        return rangeSumMap[key];
    }

private:
    vector<int> num_array;
    map<pair<int, int>, int> rangeSumMap;
    vector<int> diff;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums{9, -8};
    NumArray* obj = new NumArray(nums);
    int s;
    obj->update(0, 3);
    s = obj->sumRange(1, 1);
    cout << s << endl;
    s = obj->sumRange(0, 1);
    cout << s << endl;

    obj->update(1, -3);
    s = obj->sumRange(0, 1);
    cout << s << endl;
    return 0;
}
