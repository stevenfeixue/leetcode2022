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
    void travers(TreeNode *root) {
        if (root) {
            travers(root->left);
            inorder.push_back(root->val);
            travers(root->right);
        }
    }

    bool isSymmetric(TreeNode* root) {

        travers(root);
        auto it = inorder.begin();
        auto itt = inorder.rbegin();
        while (it < itt.base()) {
            if (*it++ != *itt++) return false;
        }
        return true;
    }

private:
    vector<int> inorder;
};

int main() {
    Solution sl;

    TreeNode a(1), b(2), c(2), d(3), e(4), f(4), g(3);
    TreeNode *p = &a;
    p->left = &b;
    p->right = &c;
    p->left->left = &d;
    p->left->right = &e;
    p->right->left = &f;
    p->right->right = &g;

    if (sl.isSymmetric(p)) cout << "true" << endl;
    else cout << "false" << endl;
}
