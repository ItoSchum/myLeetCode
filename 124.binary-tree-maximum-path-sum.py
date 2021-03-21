#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#
# https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#
# algorithms
# Hard (30.71%)
# Likes:    5329
# Dislikes: 384
# Total Accepted:    482.7K
# Total Submissions: 1.4M
# Testcase Example:  '[1,2,3]'
#
# A path in a binary tree is a sequence of nodes where each pair of adjacent
# nodes in the sequence has an edge connecting them. A node can only appear in
# the sequence at most once. Note that the path does not need to pass through
# the root.
# 
# The path sum of a path is the sum of the node's values in the path.
# 
# Given the root of a binary tree, return the maximum path sum of any path.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3]
# Output: 6
# Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 =
# 6.
# 
# 
# Example 2:
# 
# 
# Input: root = [-10,9,20,null,null,15,7]
# Output: 42
# Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
# = 42.
# 
# 
# 
# Constraints:
# 
# 
# The number of nodes in the tree is in the range [1, 3 * 10^4].
# -1000 <= Node.val <= 1000
# 
# 
#

# @lc code=start
# Definition for a binary tree node.
from math import inf

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    
    def __init__(self):
        self.global_max_path_sum = -inf
    
    def maxPathSum(self, root: TreeNode) -> int:
    
        self.localMaxPathSum(root)
        return self.global_max_path_sum  
    
    def localMaxPathSum(self, root: TreeNode) -> int:
    
        if root == None:
            return 0
    
        # max_path_sum from the left and right child nodes (if sum > 0)
        left_max_path_sum = max(0, self.localMaxPathSum(root.left) )
        right_max_path_sum = max(0, self.localMaxPathSum(root.right) )
        
        # max_path_sum of the current node
        local_max_path_sum = left_max_path_sum + right_max_path_sum + root.val
        
        # update global_max_path_sum if the current one is larger
        self.global_max_path_sum = max(self.global_max_path_sum, local_max_path_sum)
        
        return (max(left_max_path_sum, right_max_path_sum) + root.val)
        
# @lc code=end

# n = node amount
# Time: O( n )
# Storage: O( log(n) )

