#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int computeCharNum(string s) {
	set<char>  alphas;
        for (char c: s) {
	    alphas.insert(c);
	}
        return alphas.size();
    }

    bool check(string s) {
        return (computeCharNum(s) == s.size());
    }

    int lengthOfLongestSubstring(string s) {
	auto len = s.size();
	int n = computeCharNum(s);
	for (int i=n; i>0; --i) {
	    for (int j=0; j<len-i+1; ++j) {
	        string res = s.substr(j, i);
		if (check(res)) {
		    return i;
		}
	    }
	}
        return 0;
    }
};


int main() {

    Solution sl;
    string str{"abcdefghi"};
    int res = s.lengthOfLongestSubstring(str);
    cout << res << endl;
    return 0;
}
