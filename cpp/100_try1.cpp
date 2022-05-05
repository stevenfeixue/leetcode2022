/*
 * no.100 https://leetcode-cn.com/problems/same-tree/
 *  4ms 39.37%
 *  9.6MB 80.75%
 */

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
    bool isLeaf(TreeNode *p) {
        return !p->left && !p->right;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && q) {
            if (isLeaf(p) && isLeaf(q)) {
               return p->val == q->val;
            } else if (!isLeaf(p) && !isLeaf(q)) {
               return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else {
               return false;
            }
        }
        return false;
    }
};

int main() {
    Solution sl;
    if (sl.isSameTree(nullptr, nullptr)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
