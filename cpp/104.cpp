/*
 * No.104 https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 */
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (left > right) return left+1;
        else return right+1;
    }
};

int main() {
    Solution sl;

    TreeNode a(5), b(4), c(1), d(1), e(4), f(2), g(2);
    TreeNode *p = &a;
    p->left = &b;
    p->right = &c;
    p->left->right = &d;
    p->left->right->left = &f;
    p->right->right = &e;
    p->right->right->left = &g;

    cout << sl.maxDepth(p) << endl;
    return 0;
}
