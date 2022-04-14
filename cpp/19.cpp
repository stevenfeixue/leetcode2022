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
    int calNodeAmount(ListNode *head) {
        ListNode *p = head;
        int amount = 0;
        while (p) {
            amount++;
            p = p->next;
        }
        return amount;
    }
     
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int amount = calNodeAmount(head);
        int nth = amount - n + 1;
        ListNode *p = head;
        if (nth == 1) {
            head = p->next;
        } else {
            for (int i=1; i<nth-1; ++i) p=p->next;
            auto tmp = p->next;
            p->next = p->next->next;
            tmp->next = nullptr;
        }
        return head;
    }
};


int main() {
    ListNode a(1), b(2), c(3), d(4);
    ListNode *p = &a;
    p->next = &b;
    p->next->next = &c;
    p->next->next->next = &d;
    p = removeNthFromEnd(p, 4);
 
    while (p) {
        cout << p->val << endl;
        p=p->next;
    }
    return 0;
}
