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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newList = nullptr, *ptr = nullptr;
        int num;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                num = list1->val;
                list1 = list1->next;
            } else {
                num = list2->val;
                list2 = list2->next;
            }
            if (!ptr) {
                newList = new ListNode(num);
                ptr = newList;
            } else {
                ptr->next = new ListNode(num);
                ptr = ptr->next;
            }
        }
        if (list1) {
            if (!ptr)
                newList = list1;
            else
                ptr->next = list1;
        }
        if (list2) {
            if (!ptr)
                newList = list2;
            else
                ptr->next = list2;
        }
        return newList;
    }
};