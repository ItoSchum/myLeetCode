#
# @lc app=leetcode id=1209 lang=python3
#
# [1209] Remove All Adjacent Duplicates in String II
#
# https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
#
# algorithms
# Medium (57.16%)
# Likes:    1638
# Dislikes: 35
# Total Accepted:    103K
# Total Submissions: 180.3K
# Testcase Example:  '"abcd"\n2'
#
# You are given a string s and an integer k, a k duplicate removal consists of
# choosing k adjacent and equal letters from s and removing them, causing the
# left and the right side of the deleted substring to concatenate together.
# 
# We repeatedly make k duplicate removals on s until we no longer can.
# 
# Return the final string after all such duplicate removals have been made. It
# is guaranteed that the answer is unique.
# 
# 
# Example 1:
# 
# 
# Input: s = "abcd", k = 2
# Output: "abcd"
# Explanation: There's nothing to delete.
# 
# Example 2:
# 
# 
# Input: s = "deeedbbcccbdaa", k = 3
# Output: "aa"
# Explanation: 
# First delete "eee" and "ccc", get "ddbbbdaa"
# Then delete "bbb", get "dddaa"
# Finally delete "ddd", get "aa"
# 
# Example 3:
# 
# 
# Input: s = "pbbcggttciiippooaais", k = 2
# Output: "ps"
# 
# 
# 
# Constraints:
# 
# 
# 1 <= s.length <= 10^5
# 2 <= k <= 10^4
# s only contains lower case English letters.
# 
# 
#

# @lc code=start
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        # return self.removeByCount(s, k)
        return self.removeByStack(s, k)
        
    # Solution 1: Brutal
    # Solution 2: Duplication counter
    def removeByCount(self, s: str, k: int) -> str:
        if s == None:
            return s

        dupCount = []
        i = 0        
        while i < len(s):
            if i == 0 or s[i] != s[i - 1]:
                dupCount.append(1)
            else:
                dupCount.append(dupCount[i - 1] + 1)
                if dupCount[i] == k:
                    dupCount = dupCount[0: i - k + 1]
                    # print(dupCount)
                    s = s[0: i - k + 1] + s[i + 1: ]
                    # print(s)
                    i = i - k
            i += 1
        return s
        
    # Solution 3: Duplication stack
    def removeByStack(self, s: str, k: int) -> str:
        if s == None:
            return s
        
        dupCountStack = []
        i = 0
        stack_seq = -1
        while i < len(s):
            if i == 0 or s[i] != s[i - 1]:
                dupCountStack.append(1)
                stack_seq += 1
            else:
                dupCountStack[stack_seq] += 1
                if dupCountStack[stack_seq] == k:
                    dupCountStack = dupCountStack[0:stack_seq]
                    stack_seq -= 1
                    
                    s = s[0: i - k + 1] + s[i + 1: ]
                    i = i - k
            i += 1
        return s
        
# @lc code=end
# n = string length
# Time: O(n)
# Space: O(n)

