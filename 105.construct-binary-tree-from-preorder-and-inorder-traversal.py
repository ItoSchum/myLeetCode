#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
#
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#
# algorithms
# Medium (42.68%)
# Likes:    4888
# Dislikes: 124
# Total Accepted:    472K
# Total Submissions: 905.6K
# Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
#
# Given two integer arrays preorder and inorder where preorder is the preorder
# traversal of a binary tree and inorder is the inorder traversal of the same
# tree, construct and return the binary tree.
# 
# 
# Example 1:
# 
# 
# Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
# Output: [3,9,20,null,null,15,7]
# 
# 
# Example 2:
# 
# 
# Input: preorder = [-1], inorder = [-1]
# Output: [-1]
# 
# 
# 
# Constraints:
# 
# 
# 1 <= preorder.length <= 3000
# inorder.length == preorder.length
# -3000 <= preorder[i], inorder[i] <= 3000
# preorder and inorder consist of unique values.
# Each value of inorder also appears in preorder.
# preorder is guaranteed to be the preorder traversal of the tree.
# inorder is guaranteed to be the inorder traversal of the tree.
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
    
    def __init__(self):
        self.preorder = []
        self.inorder = []
        self.value_to_inorder_position = dict()
    
    # Assign the given order list to memeber variable
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:    
        
        self.preorder = preorder
        self.inorder = inorder
        
        # generate the dictionary value -> serial num in inorder list
        for i in range(len(inorder) ):
            self.value_to_inorder_position[self.inorder[i]] = i
            
        root = self.buildSubTree(0, len(preorder) - 1, 0, len(inorder) - 1)
        return root 

    def buildSubTree(self, preStart: int, preEnd: int, inStart: int, inEnd: int) -> TreeNode:
        
        # if out of range
        if preStart > preEnd or inStart > inEnd:
            return None
        
        # Generate the current node
        root = TreeNode(self.preorder[preStart])
        # Calculate the serial num of the current node in inorder list
        inorder_root_position = self.value_to_inorder_position[root.val]
        # Calculate the child nodes on the left
        left_child_node_amount = inorder_root_position - inStart
        
        # Build child nodes
        root.left = self.buildSubTree(
            preStart=preStart + 1, 
            preEnd=preStart + left_child_node_amount,
            inStart=inStart,
            inEnd=inorder_root_position - 1)
        
        root.right = self.buildSubTree(
            preStart=preStart + left_child_node_amount + 1, 
            preEnd=preEnd,
            inStart=inorder_root_position + 1,
            inEnd=inEnd)
        return root
# @lc code=end

# n = node amount
# Time: O( n )
# Storage: O( n/2 )
