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
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode *fast = head;
        ListNode *slow = head;
        if (!fast) return nullptr;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        } else
            return nullptr;
    }
};


int main() {
    Solution sl;
    ListNode A(0), B(6), C(7), D(8);
    ListNode *q = &A;
    q->next = &B;
    q->next->next = &C;
    q->next->next->next = &D;
    D.next = &C;
    ListNode *enter = sl.detectCycle(q);
    cout << enter->val << endl;
    return 0;
}
