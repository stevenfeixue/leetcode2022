/*
 * No.9 https://leetcode-cn.com/problems/palindrome-number/ 
 */
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        deque<int> dq;

        if (x<0) return false;
        if (!x) return true;

        while (x) {
            dq.push_back(x % 10);
            x = x / 10;
        }
        auto it = dq.begin();
        auto rit = dq.rbegin();
        bool is_palindrome = true;
        while (it <= rit.base()) {
            if (*it++ != *rit++) {
                is_palindrome = false;
                break;
            }
        }
        return  is_palindrome;
    }
};

int main() {
    int x = 1001;
    Solution sl;
    bool ret = sl.isPalindrome(x);
    if (ret) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
