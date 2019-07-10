# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
	def removeElements(self, head: ListNode, val: int) -> ListNode:

		while head != None and head.val == val:
			head = head.next
		if head == None:
			return None
		
		prev_node = head
		cur_node = head.next

		while cur_node != None:
			if cur_node.val == val:
				prev_node.next = cur_node.next
				cur_node = cur_node.next
			else:
				prev_node = prev_node.next
				cur_node = cur_node.next

		return head

# Runtime: 80 ms, faster than 33.76% of Python3 online submissions for Remove Linked List Elements.
# Memory Usage: 16.3 MB, less than 81.22% of Python3 online submissions for Remove Linked List Elements.

# TC: O(n), n = length of the given node list
# SC: O(n), n = length of the given node list