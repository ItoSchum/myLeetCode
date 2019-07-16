class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        nums_len = len(nums)        
        
        if target < nums[0]:
            return 0
        elif target > nums[-1]:
            return nums_len

        leading_index = 0
        ending_index = nums_len - 1
        
        while leading_index < ending_index - 1:
            middle_index = (leading_index + ending_index) // 2
            
            if nums[middle_index] == target:
                return middle_index
            elif nums[middle_index] > target:
                ending_index = middle_index
            elif nums[middle_index] < target:
                leading_index = middle_index

        if nums[leading_index] == target:
            return leading_index
        elif nums[ending_index] == target:
            return ending_index

        if nums[leading_index] > target:
            return leading_index
        elif nums[leading_index] < target and nums[ending_index] > target:
            return leading_index + 1
        elif nums[ending_index] < target:
            return ending_index + 1

# Runtime: 36 ms, faster than 71.57% of Python3 online submissions for Search Insert Position.
# Memory Usage: 13.6 MB, less than 74.35% of Python3 online submissions for Search Insert Position.

# TC: O(log2(n)), n = nums_len
# SC: O(1)


