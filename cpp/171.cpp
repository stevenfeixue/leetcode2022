#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

static const int alpha[26] = {
  'A','B','C','D','E','F','G','H','I','J',
  'K','L','M','N','O','P','Q','R','S','T',
  'U','V','W','X','Y','Z'};

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber) {
            res.insert(res.begin(), alpha[(columnNumber-1)%26]);
            columnNumber = (columnNumber -1) / 26;
        }
        return res;
    }

    int titleToNumber(string columnTitle) {
        int sum = 0;
        int digit = 0;
        for (auto rit = columnTitle.rbegin(); rit != columnTitle.rend(); ++rit) {
            sum += (*rit - 'A' + 1) * pow(26, digit++) ;   // turn 'A' to 0
        }
        return sum;
    }
};


int main() {
    Solution sl;
    vector<string> data{"A", "Z", "AA", "AZ", "ZY", "FXSHRXW"};
    for (auto s: data)
        cout << sl.titleToNumber(s) << endl;

    return 0;
}
