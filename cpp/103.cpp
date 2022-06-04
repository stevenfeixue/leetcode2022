/*
 * No.103 https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int>  levelData;
        vector<vector<int>>  result;
        deque<pair<TreeNode *, int>> q;
        pair<TreeNode *, int> *cur;
        TreeNode *p;
        int h, cur_height;
        if (!root) return result;

        p = root;
        q.push_back(make_pair(p, 1));  // root node height is 1
        cur_height = 0;
        while (!q.empty()) {
            cur = &q.front();
            h = cur->second;
            if (h != cur_height) {
                if (cur_height) {
                    if (!(cur_height%2))
                        reverse(levelData.begin(), levelData.end());
                    result.push_back(levelData);
                }
                levelData.clear();
                cur_height = h;
            }  
            levelData.push_back(cur->first->val);

            if (cur->first->left) {
                q.push_back(make_pair(cur->first->left, cur_height+1));
            }
            if (cur->first->right) {
                q.push_back(make_pair(cur->first->right, cur_height+1));
            }
            q.pop_front();
        }
        if (!(cur_height%2))
            reverse(levelData.begin(), levelData.end());
        result.push_back(levelData);
        return result;
    }
};


/*
       1
      / \
     2   3
    /   / \
   10  4   5
 */
int main() {
    Solution sl;

    TreeNode a(1), b(2), c(3), d(4), e(5), f(10);
    TreeNode *p = &a;
    p->left = &b;
    //p->left->left = &f;
    p->right = &c;
    //p->right->left = &d;
    //p->right->right = &e;

    auto ret = sl.zigzagLevelOrder(p);
    for (auto levelData: ret) {
        for (auto i: levelData) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
