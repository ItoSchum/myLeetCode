# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # point end_node.next == None
        leading_node = head
        # point the former node of the node to be replaced
        tail_node = head

        for i in range(n + 1):
            if leading_node != None:
                leading_node = leading_node.next
            else:
                return head.next

        while leading_node != None:
            leading_node = leading_node.next
            tail_node = tail_node.next
            
        tail_node.next = tail_node.next.next

        return head

# Runtime: 40 ms, faster than 61.25% of Python3 online submissions for Remove Nth Node From End of List.
# Memory Usage: 13.2 MB, less than 38.01% of Python3 online submissions for Remove Nth Node From End of List.

# TC: O(n), n = length of the node list
# SC: O(1)