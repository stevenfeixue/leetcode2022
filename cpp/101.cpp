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
    bool travers(TreeNode *root) {
        if (root) {
            if (!root->left && root->right) {
                root->left = new TreeNode(999);
            } else if (root->left && !root->right) {
                root->right = new TreeNode(999);
            }
            travers(root->left);
            inorder.push_back(root->val);
            travers(root->right);
        }
        return true;
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

    TreeNode a(1), b(2), c(2), d(2), f(2);
    TreeNode *p = &a;
    p->left = &b;
    p->right = &c;
    p->left->left = &d;
    p->left->right = nullptr;
    p->right->left = &f;
    p->right->right = nullptr;

    if (sl.isSymmetric(p)) cout << "true" << endl;
    else cout << "false" << endl;
}
