class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def num_swap(nums: List[int], cur_index: int, ref_index: int):
            temp = nums[cur_index]
            nums[cur_index] = nums[ref_index]
            nums[ref_index] = temp

        nums_len = len(nums)
        cur_index = nums_len - 2

        while cur_index >= 0 and nums[cur_index + 1]  <= nums[cur_index]:
            cur_index -= 1
        
        if cur_index >= 0:
            ref_index = nums_len - 1
            while ref_index > 0 and nums[ref_index] <= nums[cur_index]:
                ref_index -= 1

            num_swap(nums, cur_index, ref_index)

        leading_index = cur_index + 1
        ending_index = nums_len - 1
        while leading_index < ending_index:
            num_swap(nums, leading_index, ending_index)
            leading_index += 1
            ending_index -= 1


# Runtime: 32 ms, faster than 99.34% of Python3 online submissions for Next Permutation.
# Memory Usage: 13.2 MB, less than 43.70% of Python3 online submissions for Next Permutation.

# TC: O(n), n = nums_len
# SC: O(1)
                
        