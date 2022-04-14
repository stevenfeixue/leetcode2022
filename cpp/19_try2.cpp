/*
 * No.19 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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
    void reverse(ListNode **head) {
        ListNode *p = nullptr;
        ListNode *q = *head;
        if (!q) return;
        ListNode *r = q->next;
        if (!r) return;
        while (r) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        *head = q;
    }
     
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        reverse(&head);

        if (n == 1) {
            head = head->next;
            reverse(&head);
            return head;
        }

        auto *p = head;
        for (int i=1; i<n-1; ++i) p=p->next;
        auto tmp = p->next;
        p->next = p->next->next;
        tmp->next = nullptr;
        reverse(&head);

        return head;
    }
};


int main() {
    Solution sl;
    ListNode a(1), b(2), c(3), d(4);
    ListNode *p = &a;
    p->next = &b;
    p->next->next = &c;
    p->next->next->next = &d;
    p = sl.removeNthFromEnd(p, 1);
 
    while (p) {
        cout << p->val << "~";
        p=p->next;
    }
    cout << endl;
    return 0;
}
