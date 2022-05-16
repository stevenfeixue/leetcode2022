/*
 * No.83 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
 * 16ms 6.55%
 * 11.3MB 53.61%
 */

#include <iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p  = head;
        if (!p) return p;
        ListNode *q = p->next;
        if (!q) return p;

        while (q) {
            if (p->val == q->val) {
                p->next = q->next;
                q->next = NULL;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};


int main() {
    ListNode a(1), b(2), c(3), d(3);
    ListNode *p = &a;
    p->next = &b;
    p->next->next = &c;
    p->next->next->next = &d;
    Solution sl;
    p = sl.deleteDuplicates(p);

    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
