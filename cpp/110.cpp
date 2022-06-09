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

    bool isBalanced(TreeNode* root) {
        int hl, hr;
        if (!root) return true;

        hl = height(root->left);
        hr = height(root->right);
        if (isBalanced(root->left) && isBalanced(root->right) && abs(hl - hr) < 2) return true;
        else return false;
    }

    int height(TreeNode *root) {
        int hl, hr;
        if (!root) return 0;
        hl = height(root->left);
        hr = height(root->right);
        if (hl > hr)
            return hl+1;
        else
            return hr+1;
    }
};

/*
       1
      / \
     2   3
    /   / \
   10  4   5
            \
            1000
 */
int main() {
    Solution sl;

    TreeNode a(1), b(2), c(3), d(4), e(5), f(10), g(1000), h(1001);
    TreeNode *p = &a;
    p->left = &b;
    p->left->left = &f;
    p->right = &c;
    p->right->left = &d;
    p->right->right = &e;
    p->right->right->right = &g;
    p->right->right->right->right = &h;

    cout << "height:" << sl.height(p) << endl;

    auto ret = sl.isBalanced(p);
    cout << ret << endl;
    return 0;
}
