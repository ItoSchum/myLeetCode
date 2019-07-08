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
