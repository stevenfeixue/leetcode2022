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

    string reverseWords(string s) {
        int size = s.size();
        size = trim(s, size);
        reverse(s.begin(), s.end());
        trim(s, size); 
        
        return s;
    }
};


int main() {
    Solution sl;
    string s{"    the  blue  sky       "};
    cout << sl.reverseWords(s) << endl;
    return 0;
}
