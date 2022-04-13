/*
 * No2. https://leetcode-cn.com/problems/add-two-numbers/
 */
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head{nullptr}, *last, *p;
        ListNode zero(0);
        ListNode *dummy = &zero;
        int tmp;
        bool carry_flag = false;
        while (l1 || l2) {
            if (!l1) l1 = dummy;
            if (!l2) l2 = dummy;
            tmp = l1->val + l2->val + (carry_flag?1:0);
            if (tmp / 10) {
                carry_flag = true;
                tmp = tmp % 10;
            } else {
                carry_flag = false;
            }
            p = new ListNode(tmp);
            if (!head) {
                head = p;
                last = head;
            } else {
                last->next = p;
                last = p;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry_flag) {
            last->next = new ListNode(1);
        }
        return head;
    }
};

int main() {
    Solution sl;
    ListNode *pa, *pb;
    ListNode a1(0), a2(9), a3(9);
    ListNode b1(0), b2(9), b3(9);
    pa = &a1; pa->next = &a2; pa->next->next = &a3;
    pb = &b1; pb->next = &b2; pb->next->next = &b3;
    ListNode *result = sl.addTwoNumbers(pa, pb);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
