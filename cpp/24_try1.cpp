/*
 * No.24 https://leetcode-cn.com/problems/swap-nodes-in-pairs/submissions/
 * 4 ms   51.75%
 * 7.3 MB 53.50%
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p  = head, *new_head = nullptr;
        if (!head || !head->next) return head;
        ListNode *q = p, *tmp; 
        ListNode *last_pair;
        bool exit_flag = false;
        while (!exit_flag && p->next) {
            tmp = p;
            p = p->next;
            q = p->next;
            p->next = tmp;
            if (!q) {
                tmp->next = q;
                exit_flag = true;
            } else {
                tmp->next = q->next;
            }
           
            if (!new_head) new_head = p;
            p = q;
            last_pair = tmp;
        }
        last_pair->next = p;
        return new_head;
    }
};

int main() {
    ListNode a(11), b(12), c(13), d(14), e(15), f(16);
    ListNode *p = &a;
    p->next = &b;
    p->next->next = &c;
    p->next->next->next = &d;
    p->next->next->next->next = &e;
    p->next->next->next->next->next = &f;

    Solution sl;
    auto ret = sl.swapPairs(p);
 
    while (ret) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}

