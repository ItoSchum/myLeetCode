# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        if l1 is None:
            return l2
        
        if l2 is None:
            return l1
        
        if l1.val <= l2.val:
            current_node = l1
            waiting_node = l2
        else:
            current_node = l2
            waiting_node = l1
        
        head = current_node

        while current_node or waiting_node:
            if current_node.next is None:
                current_node.next = waiting_node
                return head
            
            if waiting_node is None:
                return head
            
            if current_node.next.val <= waiting_node.val:
                current_node = current_node.next
            else:
                temp_node = current_node.next
                current_node.next = waiting_node
                waiting_node = temp_node


# Runtime: 40 ms, faster than 84.82% of Python3 online submissions for Merge Two Sorted Lists.
# Memory Usage: 13.1 MB, less than 83.01% of Python3 online submissions for Merge Two Sorted Lists.

# TC: O(n + m), n = length of l1, m = length of l2
# SC: O(1)