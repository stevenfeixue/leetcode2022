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
     
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head, *slow = head;
        while (n--) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            return head->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        

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
