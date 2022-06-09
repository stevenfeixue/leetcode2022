#include <iostream>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        dfs(root, tmp, targetSum);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &tmp, int targetSum) {
        if (!root) return;

        tmp.push_back(root->val);
        if (!root->left && !root->right && root->val == targetSum) {
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }  

        dfs(root->left, tmp, targetSum - root->val);

        dfs(root->right, tmp, targetSum - root->val);

        tmp.pop_back();
    }

private:
    vector<vector<int>> res;
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

    TreeNode a(5), b(4), c(8), d(11), e(13), f(4), g(7), h(2), i(5), j(1);
    TreeNode *p = &a;
    p->left = &b;
    p->right = &c;

    b.left = &d;
    c.left = &e;
    c.right = &f;

    d.left= &g;
    d.right = &h;
    f.left = &i;
    f.right = &j;


    auto ret = sl.pathSum(p, 22);
    for (auto v: ret) {
        for (auto i: v) 
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
