/*
 * No.21 https://leetcode-cn.com/problems/merge-two-sorted-lists/submissions/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode *p = list1;
       ListNode *q = list2;
       ListNode *l, *head;

       if (!list1) return list2;
       if (!list2) return list1;

       if (list1->val <= list2->val) {
           head = list1;
           p = list1->next;
       } else {
           head = list2;
           q = list2->next;
       }
       l = head;

       while (p && q) {
           if (p->val <= q->val) {
               l->next = p;
               l = p;
               p = p->next;
           } else {
               l->next = q;
               l = q;
               q = q->next;
           }
       }
       if (!p) {
           l->next = q;
       } else {
           l->next = p;
       }
       return head;
    }
};

int main() {
    ListNode a(11), b(12), c(13), d(14);
    ListNode *p = &a;
    p->next = &b;
    p->next->next = &c;
    p->next->next->next = &d;

    ListNode A(0), B(6), C(7), D(8);
    ListNode *q = &A;
    q->next = &B;
    q->next->next = &C;
    q->next->next->next = &D;

    Solution sl;
    auto ret = sl.mergeTwoLists(p, q);
 
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
