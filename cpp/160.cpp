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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p, *q, *s;
        ListNode *pa = headA;
        ListNode *pb = headB;
        int i = 0;
        while (pa && pb) {
            pa = pa->next;
            pb = pb->next;
        }
        if (!pa) {
            p = pb;
            q = headB;
            s = headA;
        }
        else {
            p = pa;
            q = headA;
            s = headB;
        }
        while (p) {
            p = p->next;
            q = q->next;
            i++;
        }
        while (q != s) {
            q = q->next;
            s = s->next;
        }
        return q;
    }
};

