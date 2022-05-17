/*
 * No.70 https://leetcode.cn/problems/climbing-stairs/
 * 0ms 100%
 * 5.9MB 55.32%
 */

#include <iostream>

using namespace std;

static int dp[45] = {1, 2};

class Solution {
public:
    int climbStairs(int n) {
        int total;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (dp[n]) {
            return dp[n];
        } else {
            total = climbStairs(n-1) + climbStairs(n-2);
            dp[n] = total;
        }
        return total;
    }
};

int main() {
    Solution sl;
    cout << sl.climbStairs(2) << endl;
    cout << sl.climbStairs(3) << endl;
    cout << sl.climbStairs(44) << endl;
    return 0;
}
