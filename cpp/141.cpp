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
    bool hasCycle(ListNode *head) {
        ListNode *fast;
        ListNode *slow = head;;
        if (!slow) return false;
        fast = slow->next;
        if (!fast) return false;
        cout << sizeof(ListNode) << endl;
        while (fast && fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            else fast = fast->next;
        }
        if (!fast) return false;
        else return true;
    }
};


int main() {
    Solution sl;
    ListNode A(0), B(6), C(7), D(8);
    ListNode *q = &A;
    q->next = &B;
    q->next->next = &C;
    q->next->next->next = &D;
    D.next = &D;
    cout << sl.hasCycle(q) << endl;

}
