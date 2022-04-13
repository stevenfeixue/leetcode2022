#include <iostream>
#include <deque>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> window;
        map<char, bool> table;
        int max_sub_len{0};
        int cur_sub_len{0};
        bool repeat_flag = false;
        for (auto c: s) {
            if (table.find(c) != table.end()) {  // found
                repeat_flag = true;
                while (!window.empty() && (window.front() != c)) {
                    table.erase(window.front());
                    window.pop_front();
                }
                table.erase(window.front());
                window.pop_front();
                if (window.size() > max_sub_len) max_sub_len = window.size();
            }
            window.push_back(c);
            table[c] = true;
            cur_sub_len = window.size();
            if (cur_sub_len > max_sub_len) max_sub_len = cur_sub_len;
        }
        if (!repeat_flag) {
            max_sub_len = window.size();
        }
        return max_sub_len;
    }
};

int main() {
    Solution sl;
    //string mystr{"nfpdmpi"};
    //string mystr{"dvdf"};
    //string mystr{"abcabcbb"};
    string mystr{"pwwkew"};
    auto r = sl.lengthOfLongestSubstring(mystr);
    cout << r << endl;
    return 0;
}
