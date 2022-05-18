/*
 * No.101 https://leetcode.cn/problems/symmetric-tree/
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
    bool travers(TreeNode *left, TreeNode *right) {
        if (!left && right) return false;
        if (left && !right) return false;
        if (!left && !right) return true;
        if (left && right && left->val == right->val) 
            return travers(left->left, right->right) && travers(left->right, right->left);
        else
            return false;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        return travers(l, r);
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


//    TreeNode a(1), b(3), c(2), d(3), e(4), f(4), g(3);
//    TreeNode *p = &a;
//    p->left = &b;
//    p->right = &c;
//    p->left->left = &d;
//    p->left->right = &e;
//    p->right->left = &f;
//    p->right->right = &g;

    if (sl.isSymmetric(p)) cout << "true" << endl;
    else cout << "false" << endl;
}
