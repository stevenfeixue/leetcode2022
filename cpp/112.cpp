#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == targetSum)
            return true;

        if (hasPathSum(root->left, targetSum - root->val) ||
              hasPathSum(root->right, targetSum - root->val))
            return true;
        else
            return false;
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
    p->left->left = &f;
    p->right = &c;
    p->right->left = &d;
    p->right->right = &e;


    auto ret = sl.hasPathSum(p, 9);
    cout << ret << endl;
    return 0;
}
