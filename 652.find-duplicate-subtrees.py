#
# @lc app=leetcode id=652 lang=python3
#
# [652] Find Duplicate Subtrees
#
# https://leetcode.com/problems/find-duplicate-subtrees/description/
#
# algorithms
# Medium (46.61%)
# Likes:    1938
# Dislikes: 241
# Total Accepted:    92.2K
# Total Submissions: 173.4K
# Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
#
# Given the root of a binary tree, return all duplicate subtrees.
# 
# For each kind of duplicate subtrees, you only need to return the root node of
# any one of them.
# 
# Two trees are duplicate if they have the same structure with the same node
# values.
# 
# 
# Example 1:
# 
# 
# Input: root = [1,2,3,4,null,2,4,null,null,4]
# Output: [[2,4],[4]]
# 
# 
# Example 2:
# 
# 
# Input: root = [2,1,1]
# Output: [[1]]
# 
# 
# Example 3:
# 
# 
# Input: root = [2,2,2,3,null,3,null]
# Output: [[2,3],[3]]
# 
# 
# 
# Constraints:
# 
# 
# The number of the nodes in the tree will be in the range [1, 10^4]
# -200 <= Node.val <= 200
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
    existing_seq = dict()
    duplicate_root_node_list = []
    
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        self.existing_seq = dict()
        self.duplicate_root_node_list.clear()
        
        self.traverse(root)
        return self.duplicate_root_node_list
        
    def traverse(self, root: TreeNode):
        if root == None:
            return 'null'
        
        left_seq = self.traverse(root.left)
        right_seq = self.traverse(root.right)
        
        curr_seq = left_seq + ',' + right_seq + ',' + str(root.val)
        if curr_seq in self.existing_seq:
            if self.existing_seq[curr_seq] == 1:
                self.duplicate_root_node_list.append(root)
            self.existing_seq[curr_seq] += 1
        else:
            self.existing_seq[curr_seq] = 1
        return curr_seq 
            
# @lc code=end

# n = node number
# Time: O(n)
# Space: O(n!) = O(n^2 / 2)


