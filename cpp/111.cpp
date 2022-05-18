/*
 * No.111 https://leetcode.cn/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!left) return right +1;
        if (!right) return left +1; 
        if (left > right) return right+1;
        else return left+1;
    }
};

int main() {
    Solution sl;

    TreeNode a(5), b(4), f(10), c(1), d(1), e(4), g(2);
    TreeNode *p = &a;
    p->left = &b;
    p->right = &c;
    p->left->left = &f;
    p->left->right = &d;
    p->right->right = &e;
    p->right->right->left = &g;

    cout << sl.minDepth(p) << endl;
    return 0;
}
