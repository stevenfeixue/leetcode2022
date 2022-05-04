/*
 * No. 13 https://leetcode-cn.com/problems/roman-to-integer/
 *  12 ms 61.14%
 *  5.8 MB 84.10%
 */
#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    int val(char d) {
        int x;
        switch (d) {
            case 'I': x = 1; break;
            case 'V': x = 5; break;
            case 'X': x = 10; break;
            case 'L': x = 50; break;
            case 'C': x = 100; break;
            case 'D': x = 500; break;
            case 'M': x = 1000; break;
        }
        return x;
    }

    int romanToInt(string s) {
        int num{0};
        int len = s.size();
        for (int i=0; i<len; ++i) {
           int tmp = val(s[i]);
           auto sub = s.substr(i, 2);
           if (sub == "IV" || sub == "IX"
               || sub == "XL" || sub == "XC"
               || sub == "CD" || sub == "CM")
               tmp *= -1;

           num += tmp;
        }
        return num;
    }
};

int main() {
    //string num{"IX"};
    string num{"MCMXCIV"};
    Solution sl;
    cout << sl.romanToInt(num) << endl;
    return 0;
}
