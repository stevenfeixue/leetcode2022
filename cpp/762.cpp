/*
 * 762: https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/
 */
#include <iostream>
#include <deque>
 
using namespace std;
 
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int prime_count = 0;
        for (int i=left; i<=right; ++i) {
            int one_count = bits_count(i);
            if (is_prime(one_count)) {
                prime_count++;
            }
        }
        return prime_count;
    }
 
    int bits_count(int x) {
        int count = 0;
        deque<int> bits;
        while (x) {
            int tmp = x % 2;
            bits.push_front(tmp);
            x = x/2;
        }
        for (auto i: bits) {
            if (i==1) count++;
        }
        return count;
    }
 
    bool is_prime(int m) {
       if (m == 1 || m == 0) return false;
       for (int i=2; i*i <= m; ++i) {
            if (!(m % i)) return false;
       }
       return true;
    }
};
 
int main() {
    Solution sl;
    int x = sl.countPrimeSetBits(10, 15);
    cout << "number of prime bits: " << x << endl;
    return 0;
}
