class Solution:
	def moveZeroes(self, nums: List[int]) -> None:
		"""
		Do not return anything, modify nums in-place instead.
		"""
		# zero_amount = nums.count(0)
		nums_len = len(nums)
		zero_count = 0
		i = 0
		while i < (nums_len - zero_count):
			if nums[i] == 0:
				nums.append(nums.pop(i))
				zero_count += 1
				i -= 1
			
			i += 1

# Runtime: 48 ms, faster than 79.29% of Python3 online submissions for Move Zeroes.
# Memory Usage: 14.3 MB, less than 92.19% of Python3 online submissions for Move Zeroes.

# TC: O(n), n = nums_len
# SC: O(1)