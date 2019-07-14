# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        
        if head == None:
            return head

        dummy = ListNode(0)
        dummy.next = head

        navi_node = dummy
        last_but_one_node = dummy.next
        last_node = dummy.next.next

        while last_node != None:
            last_but_one_node.next = last_node.next
            last_node.next = last_but_one_node
            navi_node.next = last_node

            navi_node = last_but_one_node
            last_but_one_node = navi_node.next
            
            if last_but_one_node != None:
                last_node = navi_node.next.next
            else:
                break

        return dummy.next

# Runtime: 36 ms, faster than 72.22% of Python3 online submissions for Swap Nodes in Pairs.
# Memory Usage: 13.3 MB, less than 17.16% of Python3 online submissions for Swap Nodes in Pairs.

# TC: O(n), n = length of the node list
# SC: O(1)

