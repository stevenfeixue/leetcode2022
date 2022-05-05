/*
 * No.58 https://leetcode-cn.com/problems/length-of-last-word/
 * 0ms 100.00%
 * 6.4MB 31.93%
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len{0};
        auto rit = s.rbegin();
        if (*rit == ' ') {
            for (; rit != s.rend(); ++rit) {
                if (*rit != ' ') break;
            }
        }

        for (; rit != s.rend(); ++rit) {
            if (*rit == ' ') break;
            len++;
        }
        
        return len;
    }
};

int main() {
    //string s{"Hello world"};
    //string s{"   fly me   to   the moon  "};
    //string s{"luffy is still joyboy"};
    string s{"luffy"};
    Solution sl;
    cout << sl.lengthOfLastWord(s) << endl;
    return 0;
}
