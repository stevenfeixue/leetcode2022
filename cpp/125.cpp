#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
       auto it = s.begin();
       auto rit = s.rbegin();
       while (it < rit.base()) {
           if (!isalnum(*it)) {it++; continue; }
           if (!isalnum(*rit)) {rit++; continue; }
           if (tolower(*it) != tolower(*rit)) return false;
           it++;
           rit++;
       }
       return true;
    }
};

int main() {
    Solution sl;
    vector<string> strs{"A man, a plan, a canal: Panama", " "};
    for (auto s: strs)
        cout << sl.isPalindrome(s) << endl;
    return 0;
}
