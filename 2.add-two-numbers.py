# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum_head = ListNode(0)
        l1_node = l1
        l2_node = l2
        curr_node = sum_head
        carry = 0

        while l1_node is not None or l2_node is not None:
            
            if l1_node is not None:
                l1_value = l1_node.val
            else:
                l1_value = 0
                
            if l2_node is not None:
                l2_value = l2_node.val
            else:
                l2_value = 0

            sum_value = carry + l1_value + l2_value
            carry = sum_value // 10
            curr_node.next = ListNode(sum_value % 10)
            curr_node = curr_node.next

            if carry > 0:
                curr_node.next = ListNode(carry)
                # curr_node = curr_node.next

            if l1_node is not None:
                l1_node = l1_node.next
            if l2_node is not None:
                l2_node = l2_node.next

        return sum_head.next

# Runtime: 76 ms, faster than 79.47% of Python3 online submissions for Add Two Numbers.
# Memory Usage: 13.3 MB, less than 23.35% of Python3 online submissions for Add Two Numbers.



        
