/*
 * No.94 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 0ms 100%
 * 10.7MB 5.00%
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return res;
        res = inorderTraversal(root->left);
        res.push_back(root->val);
        res = inorderTraversal(root->right);
        return res;
    }
private:
        vector<int> res;
};

int main() {
    Solution sl;
    TreeNode *b = new TreeNode(3);
    TreeNode *a = new TreeNode(2, b, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, a) ;
    auto v = sl.inorderTraversal(root);
    for (auto i: v) {
        cout << i << endl;
    }
    return 0;
}
