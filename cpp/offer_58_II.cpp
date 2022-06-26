#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + size - n);
        reverse(s.begin() + size - n, s.end());
        return s;
    }
};

int main() {
    string s{"abcdefg"};
    Solution sl;
    cout << sl.reverseLeftWords(s, 3) << endl;
    return 0;
}
