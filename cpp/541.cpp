#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        auto start = s.begin();
        int i;
        for (i=0; i<size/(2*k); ++i) {
            reverse(start, start+k);
            start = start + 2*k;
        }
        int left = size % (2*k);
        if (left >= k) reverse(start, start+k);
        else reverse(start, s.end());
        return s;
    }
};

int main() {
    Solution sl;
    //string  s{"abcdefg"};
    string  s{"abcdABCDxyz1pq"};
    cout << sl.reverseStr(s, 4) << endl;
    return 0;
}
