#
# @lc app=leetcode id=99 lang=python3
#
# [99] Recover Binary Search Tree
#
# https://leetcode.com/problems/recover-binary-search-tree/description/
#
# algorithms
# Hard (35.46%)
# Likes:    2330
# Dislikes: 89
# Total Accepted:    205K
# Total Submissions: 481K
# Testcase Example:  '[1,3,null,null,2]'
#
# You are given the root of a binary search tree (BST), where exactly two nodes
# of the tree were swapped by mistake. Recover the tree without changing its
# structure.
# 
# Follow up: A solution using O(n) space is pretty straight forward. Could you
# devise a constant space solution?
# 
# 
# Example 1:
# 
# 
# Input: root = [1,3,null,null,2]
# Output: [3,1,null,null,2]
# Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
# makes the BST valid.
# 
# 
# Example 2:
# 
# 
# Input: root = [3,1,4,null,null,2]
# Output: [2,1,4,null,null,3]
# Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
# and 3 makes the BST valid.
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [2, 1000].
# -2^31 <= Node.val <= 2^31 - 1
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.error_node1 = None
        self.error_node2 = None
        self.inorder_traverse(root, None)
        self.swap()
        
    def inorder_traverse(self, curr: TreeNode, prev: TreeNode) -> None:     
        if curr == None: 
            return
        
        self.inorder_traverse(curr.left, prev)
          
        if prev != None and curr.val < prev.val:
            # print("Swap curr %d with prev %d" % (curr.val, prev.val) ) 
            if self.error_node1 == None:
                self.error_node1 = prev
            self.error_node2 = curr
            
        self.inorder_traverse(curr.right, curr)
        
        
    def swap(self) -> None:
        temp = self.error_node1
        self.error_node1 = self.error_node2
        self.error_node2 = temp
        
# @lc code=end

