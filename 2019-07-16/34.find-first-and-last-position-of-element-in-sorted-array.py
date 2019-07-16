class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        nums_len = len(nums)
        leftBoundary_index = self.searchBoundary(nums, target, True)

        if leftBoundary_index == nums_len or nums[leftBoundary_index] != target:
            return [-1, -1]
        else:
            rightBoundary_index = self.searchBoundary(nums, target, False) - 1
            return [leftBoundary_index, rightBoundary_index]
    
    def searchBoundary(self, nums: List[int], target: int, isSearchingLeftBoundary: bool):
        nums_len = len(nums)
        leading_index = 0
        ending_index_plus = nums_len

        while leading_index < ending_index_plus:
            middle_index = (leading_index + ending_index_plus) // 2

            if nums[middle_index] > target or (nums[middle_index] == target and isSearchingLeftBoundary is True):
                ending_index_plus = middle_index
            else:
                leading_index = middle_index + 1

        return leading_index

# Runtime: 44 ms, faster than 19.87% of Python3 online submissions for Find First and Last Position of Element in Sorted Array.
# Memory Usage: 13.8 MB, less than 87.43% of Python3 online submissions for Find First and Last Position of Element in Sorted Array.

# TC: O(log2(n)), n = nums_len
# SC: O(1)