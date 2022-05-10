/*
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int i;
        if (x == 0) return 0;
        for (i=2; i*i <= x; ++i) {
            if (i*i >= x) return i;
        }
        return i-1;
    }
};

int main() {
    Solution sl;
    cout << sl.mySqrt(0) << endl;
    cout << sl.mySqrt(8) << endl;
    cout << sl.mySqrt(INT_MAX) << endl;
    return 0;
}
