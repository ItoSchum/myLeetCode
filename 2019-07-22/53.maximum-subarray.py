class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        INT_MIN = -2 ** 31
        maxSum = max(nums)
        tempSum = INT_MIN
        for i in nums:
            tempSum += i
            if tempSum >= 0:
                maxSum = max(tempSum, maxSum)
            else:
                tempSum = 0
        
        return maxSum

# Runtime: 72 ms, faster than 6.90% of Python3 online submissions for Maximum Subarray.
# Memory Usage: 14.7 MB, less than 5.26% of Python3 online submissions for Maximum Subarray.

# TC: O(n), n = len(nums)
# SC: O(1)