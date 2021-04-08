#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#
# https://leetcode.com/problems/binary-tree-level-order-traversal/description/
#
# algorithms
# Medium (49.76%)
# Likes:    4477
# Dislikes: 104
# Total Accepted:    808.8K
# Total Submissions: 1.4M
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given the root of a binary tree, return the level order traversal of its
# nodes' values. (i.e., from left to right, level by level).
# 
# 
# Example 1:
# 
# 
# Input: root = [3,9,20,null,null,15,7]
# Output: [[3],[9,20],[15,7]]
# 
# 
# Example 2:
# 
# 
# Input: root = [1]
# Output: [[1]]
# 
# 
# Example 3:
# 
# 
# Input: root = []
# Output: []
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [0, 2000].
# -1000 <= Node.val <= 1000
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
    
    # def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
    #     level_order = []
    #     if root == None:
    #         return level_order
    #     next_level = [root]
            
    #     while len(next_level) > 0:
    #         size = len(next_level)
    #         sub = []
    #         for i in range(size):
    #             node = next_level[i]
    #             sub.append(node.val)
    #             if node.left != None:
    #                 next_level.append(node.left)
    #             if node.right != None:
    #                 next_level.append(node.right)

    #         next_level = next_level[size:]
    #         level_order.append(sub)

    #     return level_order
    
    
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        
        global_level_order = [ [root.val] ]
        curr_level = [root]
        
        while len(curr_level) > 0:
            children = []
            for node in curr_level:
                if node != None:
                    children.append(node.left)
                    children.append(node.right)

            curr_level = children
            val_list = self.nodeList_to_valueList(children)
            if len(val_list) > 0:
                global_level_order.append(val_list)     
            
        return global_level_order
    
    def nodeList_to_valueList(self, node_list: List[TreeNode]):
        val_list = []
        for node in node_list:
            if node != None:
                val_list.append(node.val)

        return val_list
            
        
# @lc code=end

# n = node number
# Time: O(n)
# Space: O(n)
