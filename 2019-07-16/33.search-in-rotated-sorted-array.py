class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums_len = len(nums)
        leading_index = 0
        ending_index = nums_len - 1

        while leading_index <= ending_index:
            middle_index = (leading_index + ending_index) // 2
            
            if nums[middle_index] == target:
                return middle_index
            else:
                if nums[middle_index] > nums[ending_index]:
                    if nums[middle_index] > target and nums[leading_index] <= target:
                        if target == nums[leading_index]:
                            return leading_index
                        else:
                            ending_index = middle_index - 1
                    else:
                        leading_index = middle_index + 1
                        if middle_index >= nums_len:
                            return -1
                else:
                    if nums[middle_index] < target and nums[ending_index] >= target:
                        if target == nums[ending_index]:
                            return ending_index
                        else:
                            leading_index = middle_index + 1
                    else:
                        ending_index = middle_index - 1
                        if ending_index < 0:
                            return -1
        
        return -1


# Runtime: 36 ms, faster than 73.05% of Python3 online submissions for Search in Rotated Sorted Array.
# Memory Usage: 13.3 MB, less than 40.82% of Python3 online submissions for Search in Rotated Sorted Array.

# TC: O(log2(n)), n = nums_len
# SC: O(1)