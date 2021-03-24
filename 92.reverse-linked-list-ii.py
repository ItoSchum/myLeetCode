#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (35.80%)
# Likes:    3448
# Dislikes: 179
# Total Accepted:    337.8K
# Total Submissions: 829.4K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Given the head of a singly linked list and two integers left and right where
# left <= right, reverse the nodes of the list from position left to position
# right, and return the reversed list.
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3,4,5], left = 2, right = 4
# Output: [1,4,3,2,5]
# 
# 
# Example 2:
# 
# 
# Input: head = [5], left = 1, right = 1
# Output: [5]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is n.
# 1 <= n <= 500
# -500 <= Node.val <= 500
# 1 <= left <= right <= n
# 
# 
# 
# Follow up: Could you do it in one pass?
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    
    def __init__(self):
        self.node_after_firstN = None
    
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if left == 1:
            print("reverseFirstN: N =", right)
            return self.reverseFirstN(head, right)
         
        head.next = self.reverseBetween(head.next, left - 1, right - 1)
        return head
    
    def reverseFirstN(self, head: ListNode, firstN: int) -> ListNode:

        # print("Current Node is %d, First: %d" % (head.val, firstN) )
        if firstN > 1 and (head == None or head.next == None):
            return head
        
        if firstN == 1:
            # print("Last Node is %d, First: %d" % (head.val, firstN) )
            self.node_after_firstN = head.next
            return head
        
        # print("Current Node is %d, First: %d" % (head.val, firstN) )
        new_link_head = self.reverseFirstN(head.next, firstN - 1)    
        head.next.next = head
        head.next = self.node_after_firstN
        
        return new_link_head
        
# @lc code=end

# n = node amount
# Time: O(n)
# Space: O(1)

