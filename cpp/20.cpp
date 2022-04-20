/*
 * No.20 https://leetcode-cn.com/problems/valid-parentheses/
 */
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        deque<char> stack;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (stack.empty()) {
                stack.push_back(*it);
            } else {
                if (match(stack.back(), *it)) stack.pop_back();
                else stack.push_back(*it);
            }
        }
        return stack.empty();
    }

    bool match(char a, char b) {
        return (a == '{' && b == '}') ||
               (a == '[' && b == ']') ||
               (a == '(' && b == ')');
    }
};

int main() {
    string  str{"({[)"};
    Solution sl;
    if (sl.isValid(str)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
