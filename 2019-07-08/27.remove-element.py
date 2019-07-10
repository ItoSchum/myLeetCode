class Solution:
	def removeElement(self, nums: List[int], val: int) -> int:

		nums_len = len(nums)
		unique_nums_len = 0
		
		while unique_nums_len < nums_len:
			if nums[unique_nums_len] == val:
				nums[unique_nums_len] = nums[nums_len - 1]
				nums_len -= 1
			else:
				unique_nums_len += 1

		return unique_nums_len

# Runtime: 32 ms, faster than 93.89% of Python3 online submissions for Remove Element.
# Memory Usage: 13.2 MB, less than 33.85% of Python3 online submissions for Remove Element.

# O(n), n = nums_len
# O(1)