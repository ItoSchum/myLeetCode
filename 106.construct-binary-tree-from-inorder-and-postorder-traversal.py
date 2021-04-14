#
# @lc app=leetcode id=106 lang=python3
#
# [106] Construct Binary Tree from Inorder and Postorder Traversal
#
# https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#
# algorithms
# Medium (40.62%)
# Likes:    2573
# Dislikes: 49
# Total Accepted:    291.4K
# Total Submissions: 580.8K
# Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
#
# Given two integer arrays inorder and postorder where inorder is the inorder
# traversal of a binary tree and postorder is the postorder traversal of the
# same tree, construct and return the binary tree.
# 
# 
# Example 1:
# 
# 
# Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
# Output: [3,9,20,null,null,15,7]
# 
# 
# Example 2:
# 
# 
# Input: inorder = [-1], postorder = [-1]
# Output: [-1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= inorder.length <= 3000
# postorder.length == inorder.length
# -3000 <= inorder[i], postorder[i] <= 3000
# inorder and postorder consist of unique values.
# Each value of postorder also appears in inorder.
# inorder is guaranteed to be the inorder traversal of the tree.
# postorder is guaranteed to be the postorder traversal of the tree.
# 
# 
#

# @lc code=start
from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.inorder = inorder
        self.postorder = postorder
        self.value_to_inorder_index = dict()
        
        for i in range(len(inorder) ):
            self.value_to_inorder_index[self.inorder[i] ] = i
        
        root = self.subBuildTree(
            inStart=0, inEnd=len(self.inorder) - 1, 
            postStart=0, postEnd=len(self.postorder) - 1)
        return root
        
    def subBuildTree(self, inStart: int, inEnd: int, postStart: int, postEnd: int) -> TreeNode:
        
        if inStart > inEnd or postStart > postEnd:
            return None
        
        root = TreeNode(self.postorder[postEnd])
        inorder_root_index = self.value_to_inorder_index[root.val]
        right_child_node_num = inEnd - inorder_root_index
        
        root.left = self.subBuildTree(
            inStart=inStart,
            inEnd=inorder_root_index - 1,
            postStart=postStart,
            postEnd=postEnd - 1 - right_child_node_num
        )
        
        root.right = self.subBuildTree(
            inStart=inorder_root_index + 1,
            inEnd=inEnd,
            postStart=postEnd - 1 - right_child_node_num + 1,
            postEnd=postEnd - 1
        )
        return root
        
# @lc code=end

# n = node number
# Time: O( n )
# Space: O( n/2 )