#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trim(string &s, int size) {
        int space_count = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (*it == ' ') space_count++;
            else break;
        }
        s.resize(size - space_count);
        return size - space_count;
    }

    int removeExtraSpaces(string &s, int size) {
        int i; /*fast index*/
        int j; /*slow index*/
        for (i=0, j=0; i<size; ++i) {
            if (i>0 && s[i-1] == s[i] && s[i] == ' ') {
                continue;
            } else
                s[j++] = s[i];
        }
        s.resize(j);
        return j;
    }

    string reverseWords(string s) {
        int size = s.size();
        size = trim(s, size);
        reverse(s.begin(), s.end());
        size = trim(s, size);
        size = removeExtraSpaces(s, size);

        auto left = s.begin();
        int n;
        while (left != s.end()) {
            n = 0;
            while ((left+n) != s.end() && *(left+n) != ' ') n++;
            
            reverse(left, left+n);

            left = left + n;
            if (left == s.end()) break;
            else
                left++;
        }
        
        return s;
    }
};


int main() {
    Solution sl;
    string s{"    abc  defgh   ijk       "};
    cout << sl.reverseWords(s) << endl;
    return 0;
}
