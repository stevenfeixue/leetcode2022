/*
 * No.9 https://leetcode-cn.com/problems/palindrome-number/ 
 */
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int saved = x;
        long int n = 0;
        while (x>0) {
            n = n*10 + x%10;
            x = x/10;
        }
        return saved == n;
    }
};

int main() {
    int x = 1234567899;
    Solution sl;
    bool ret = sl.isPalindrome(x);
    if (ret) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
