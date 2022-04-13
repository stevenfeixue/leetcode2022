#include <iostream>
#include <deque>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        map<char, int> table;
        int max_sub_len{0};
        int len = s.size();
        while (j < len) {
            if (table.find(s[j]) == table.end()) {  // not found
                table[s[j]] = j;
            } else {
                if (j - i > max_sub_len) max_sub_len = j-i;
                if (table[s[j]] >= i) {
                    i = table[s[j]]+1;
                }
                table[s[j]] = j;
            }
            j++;
        }
     
        if (j-i > max_sub_len) {
            max_sub_len = j-i;
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
