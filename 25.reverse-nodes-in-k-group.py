#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#
# algorithms
# Hard (37.57%)
# Likes:    3435
# Dislikes: 400
# Total Accepted:    337.7K
# Total Submissions: 747.2K
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# Given a linked list, reverse the nodes of a linked list k at a time and
# return its modified list.
# 
# k is a positive integer and is less than or equal to the length of the linked
# list. If the number of nodes is not a multiple of k then left-out nodes, in
# the end, should remain as it is.
# 
# Follow up:
# 
# 
# Could you solve the problem in O(1) extra memory space?
# You may not alter the values in the list's nodes, only nodes itself may be
# changed.
# 
# 
# 
# Example 1:
# 
# 
# Input: head = [1,2,3,4,5], k = 2
# Output: [2,1,4,3,5]
# 
# 
# Example 2:
# 
# 
# Input: head = [1,2,3,4,5], k = 3
# Output: [3,2,1,4,5]
# 
# 
# Example 3:
# 
# 
# Input: head = [1,2,3,4,5], k = 1
# Output: [1,2,3,4,5]
# 
# 
# Example 4:
# 
# 
# Input: head = [1], k = 1
# Output: [1]
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the list is in the range sz.
# 1 <= sz <= 5000
# 0 <= Node.val <= 1000
# 1 <= k <= sz
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return head
        
        leftBound = rightBound = head
        for _ in range(k):
            if rightBound == None:
                return head
            rightBound = rightBound.next
            
        new_head = self.reverse(leftBound, rightBound)
        leftBound.next = self.reverseKGroup(rightBound, 5)
        return new_head
        

    def reverse(self, head: ListNode, end: ListNode) -> ListNode:
        prev = None
        curr = head
        next = head
        
        while curr != end:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        return prev    
    
        
# @lc code=end

# n = node number
# Time: O(n)
# Space: O(1)