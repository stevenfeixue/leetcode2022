/*
 * No.69 https://leetcode.cn/problems/sqrtx/
 * 56ms 5.12%
 * 5.9MB 59.56%
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int i;
        if (x == 0) return 0;

        for (i=2; i<x; ++i) { 
            if (x/i == i) return i;
            else if (x/i > i) continue;
            else break;
        }
        return i-1;
    }
};

int main() {
    Solution sl;
    cout << sl.mySqrt(2) << endl;
    cout << sl.mySqrt(8) << endl;
    cout << sl.mySqrt(INT_MAX) << endl;
    return 0;
}
