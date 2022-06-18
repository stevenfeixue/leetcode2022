#include <iostream>
#include <string>


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
};


int main() {
    Solution sl;
    for (int i=27; i<=52; ++i)
        cout << sl.convertToTitle(i) << endl;
    cout << sl.convertToTitle(2147483647) << endl;
    return 0;
}
