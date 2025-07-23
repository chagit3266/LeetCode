/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
     if (!head || !head->next || k == 0)
        return head;

    // 1. חשב את גודל הרשימה
    int size = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        size++;
    }

    // 2. בצע מודולו כדי לקצר סיבובים מיותרים
    k = k % size;
    if (k == 0)
        return head;

    // 3. מצא את הנקודה שבה צריך לחתוך (size - k - 1)
    struct ListNode* current = head;
    for (int i = 0; i < size - k - 1; i++) {
        current = current->next;
    }

    // 4. קבע את הראש החדש
    struct ListNode* newHead = current->next;
    current->next = NULL;

    // 5. חבר את הזנב הישן לראש הישן
    tail->next = head;

    return newHead;
}