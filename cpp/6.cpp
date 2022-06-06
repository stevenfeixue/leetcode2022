#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "" || numRows == 0) {
		return "";
        }

        if (numRows == 1) {
		return s;
        }
        
	int p = numRows * 2 - 2;  // num of bits in a zig-zag
        int len = s.size();
        vector<string *> result;

        for (int i=0; i<numRows; ++i) {
            auto x = new string("");
            result.push_back(x);
        }

        int loop = len / p;
        int rest = len % p;

	int idx = 0;
        for (int i=0; i<loop; ++i) {
            for (int j=0; j<numRows; ++j) {
		string *pstr = result[j];
		*pstr = *pstr + s[idx++];
            }
            for (int j=numRows - 2; j>0; --j) {
		string *pstr = result[j];
		*pstr = *pstr + s[idx++];
            }
        }

        if (rest <= numRows) {
             for (int j=0; j<rest; ++j) {
		string *pstr = result[j];
		*pstr = *pstr + s[idx++];
            }
        } else {
            for (int j=0; j<numRows; ++j) {
		string *pstr = result[j];
		*pstr = *pstr + s[idx++];
            }

            int ii = numRows - 2; // this is result index
            for (int j=rest-numRows; j>0; --j) {
		string *pstr = result[ii--];
		*pstr = *pstr + s[idx++];
	    }
        }

	string zigzag;
        for (int i=0; i<numRows; ++i) {
                zigzag += *result[i];
		delete result[i];
        }

        return zigzag;
    }
};

int main() {
    Solution sl;
    string s("PAYPALISHIRING");
    string res = sl.convert(s, 4);
    cout << res << endl;
    return 0;
}

