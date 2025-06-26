/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0), *current = dummyHead;
        int carry = 0, sum = 0;
        while (l1 || l2 || carry > 0) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            sum = val1 + val2 + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            current = current->next;
        }
        return dummyHead->next;
    }
};