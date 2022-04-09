#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        auto len = s.size();
        auto len_goal = goal.size();
        if (len != len_goal) return false;

        int i = 0, j = 0;
        bool fail;

        while (true) {

            while (s[i] != goal[j]) {
                j++;
                if (i == len || j == len) {
                    return false;
                }
            }

            int ii = i;
            int jj = j;
            fail = false;
            for (int k = 0; k<len-1; ++k) {
                 ii = (ii+1) % len;
                 jj = (jj+1) % len;

                 if (s[ii] != goal[jj]) {
                     j = (j+1) % len;
                     fail = true;
                     break;
                 } 
            }
            if (!fail) return true;
        } 
        return true;
    }
};


int main() {
    string s   {"iqquydyvivwfvtgkfewecqlarygkqdxaejpfftuspeeomwvagnrdkozpztitulzxzuifmljudkjnzoeswjayjihpazilfcbpfhvv"};
    string goal{"ydyvivwfvtgkfewecqlarygkqdxaejpfftuspeeomwvagnrdkozpztitulzxzuifmljudkjnzoeswjayjihpazilfcbpfhvviqqu"};
    Solution sl;
    if (sl.rotateString(s, goal)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
