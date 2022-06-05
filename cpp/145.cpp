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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return res;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }

private:
    vector<int> res;
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

    auto res = sl.postorderTraversal(p);

    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
