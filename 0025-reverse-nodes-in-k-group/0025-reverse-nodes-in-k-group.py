# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """

        if not head or k == 1:
            return head

        dummy = ListNode(0)
        dummy.next = head
        group_prev = dummy

        while True:
            
            scan = group_prev

            for _ in range(k):
                scan = scan.next
                if not scan:
                    return dummy.next
            
            prev = None
            curr = group_prev.next
            group_tail = curr

            for _ in range(k):
                nextNode = curr.next
                curr.next = prev
                prev = curr
                curr = nextNode

            group_prev.next = prev
            group_tail.next = curr
            group_prev = group_tail

        return dummy.next