#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int number(string &str, string::iterator s, string::iterator e) {
        if (s == str.end() && e == str.end()) return 0;
        int digit = e - s;
        int sum = 0;
        while (s != e) {
            sum += (*s++ - '0') * pow(10, --digit);
        }
        return sum;
    }

    int compareVersion(string version1, string version2) {
        int x, y;
        string::iterator ps,pe, qs, qe;
        ps = pe = version1.begin();
        qs = qe = version2.begin();

        while (ps != version1.end() || qs != version2.end()) {
            while (pe != version1.end() && *pe != '.') pe++;
            x = number(version1, ps, pe);
            while (qe != version2.end() && *qe != '.') qe++;
            y = number(version2, qs, qe);
            if (x == y) {
                if (pe != version1.end())
                    pe++;
                if (qe != version2.end())
                    qe++;
                ps = pe;
                qs = qe;
            } else
                return (x-y)/abs(x-y);
        }
        return 0;
    }
};

int main() {
    Solution sl;
    string v1{"1.02"};
    string v2{"1.13"};
    cout << sl.compareVersion(v1, v2) << endl;
    return 0;
}
