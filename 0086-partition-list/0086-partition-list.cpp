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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), big(0);
        ListNode* smallPtr = &small;
        ListNode* bigPtr = &big;
        ListNode* cur = head;

        while (cur) {
            ListNode* newNode = new ListNode(cur->val);
            if (cur->val < x) {
                smallPtr->next = newNode;
                smallPtr = smallPtr->next;
            } else {
                bigPtr->next = newNode;
                bigPtr = bigPtr->next;
            }
            cur = cur->next;
        }

        smallPtr->next = big.next;
        return small.next;
    }
};