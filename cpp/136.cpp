#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> table;
        for (auto i: nums) {
            auto it = table.find(i);
            if (it != table.end()) {
                table.erase(it);
            } else {
                table.insert(make_pair(i, 1));
            }
        }
        return table.begin()->first;
    }
};

int main() {
    Solution sl;
    vector<int>  nums{4,1,2,1,2};
    cout << sl.singleNumber(nums) << endl;
    return 0;
}
