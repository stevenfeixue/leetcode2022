/*
 * No.36 https://leetcode-cn.com/problems/valid-sudoku/
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    using Loc = pair<int, int>;

    bool check_rule(char x, int i, int j, int oi, int oj) {
        return i != oi && j != oj && (i/3 != oi/3 || j/3 != oj/3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        multimap<char, Loc>  table;
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                if (table.find(board[i][j]) != table.end()) { // found
                    pair<multimap<char, Loc>::iterator, multimap<char, Loc>::iterator> ret;
                    ret = table.equal_range(board[i][j]);
                    for (multimap<char, Loc>::iterator it = ret.first; it != ret.second; ++it) {
                        if (!check_rule(board[i][j], i, j, it->second.first, it->second.second)) return false;
                    }
                }
                table.insert(make_pair(board[i][j],  make_pair(i, j)));
            }
        }
        return true;
    }
};


int main() {
//    vector<vector<char>> board { {'8','3','.','.','7','.','.','.','.'},
//                                 {'6','.','.','1','9','5','.','.','.'},
//                                 {'.','9','8','.','.','.','.','6','.'},
//                                 {'8','.','.','.','6','.','.','.','3'},
//                                 {'4','.','.','8','.','3','.','.','1'},
//                                 {'7','.','.','.','2','.','.','.','6'},
//                                 {'.','6','.','.','.','.','2','8','.'},
//                                 {'.','.','.','4','1','9','.','.','5'},
//                                 {'.','.','.','.','8','.','.','7','9'}
//                               };

vector<vector<char>> board {{'.','.','4','.','.','.','6','3','.'},{'.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','9','.'},{'.','.','.','5','6','.','.','.','.'},{'4','.','3','.','.','.','.','.','1'},{'.','.','.','7','.','.','.','.','.'},{'.','.','.','5','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'}};


    Solution sl;
    if (sl.isValidSudoku(board)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
