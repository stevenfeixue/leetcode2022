/*
 * No.7 https://leetcode-cn.com/problems/reverse-integer/
 */
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int min = 0x80000000;  // -2147483648
        int max = 0x7fffffff;  // 2147483647
        deque<int> digits;
        deque<int> max_digits;
        int b;
        int sum = 0;
        int sign = 1;

        if (x < 0) {
            if (x == min) return 0;
            sign = -1;
            x = -x;
        }


        while (max) {
            b = max % 10;
            max = max / 10;
            max_digits.push_back(b);
        }

        while (x) {
           b = x % 10;
           x = x / 10;
           digits.push_back(b);
        }
        
        size_t n = digits.size();
        size_t max_n = max_digits.size();
        if (n < max_n) {
            for (auto it = digits.begin(); it != digits.end(); ++it, --n) {
                sum += pow(10, n-1) * *it;
            }
            return sum*sign;
        } else {
            auto it = digits.begin();
            auto mit = max_digits.rbegin();

            while (it != digits.end()) {
                if (*it > *mit) return 0;
                if (*it < *mit) break;
                it++;
                mit++;
            }
    
            it = digits.begin();
            mit = max_digits.rbegin();
            while (it != digits.end()) {
                sum += pow(10, (n--)-1) * *it++;
            }
            return sum*sign;
        }
    }
};

int main() {
    //int x = -123;
    int x = -2147483648;
    Solution sl;
    int ret = sl.reverse(x);
    cout << "input: " << x << endl;
    cout << "result: " << ret << endl;
    return 0;
}
