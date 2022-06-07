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
            if (it != table.end() && it->second == 2) {
                table.erase(it);
            } else {
                if (it == table.end())
                    table.insert(make_pair(i, 1));
                else
                    table[i]++;
            }
            
        }
        return table.begin()->first;
    }
};

int main() {
    Solution sl;
    vector<int>  nums{2,2,3,2};
    cout << sl.singleNumber(nums) << endl;
    return 0;
}
