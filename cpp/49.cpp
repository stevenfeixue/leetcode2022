/*
 * 49: https://leetcode-cn.com/problems/group-anagrams/
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>
 
using namespace std;
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> table;
        vector<vector<string>> result;
        for (auto str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            table[key].push_back(str);
        }
        for (const auto& kv: table) {
            result.push_back(kv.second);
        }
        return result;
    }
};
 
int main() {
    vector<string>  strs{"eat", "ate", "tea", "byte", "tybe"};
    Solution sl;
    auto p = sl.groupAnagrams(strs);
    for (auto i: p) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "\n";
    }
 
    return 0;
}
