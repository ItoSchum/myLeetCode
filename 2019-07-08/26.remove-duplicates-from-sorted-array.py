class Solution:
	def removeDuplicates(self, nums: List[int]) -> int:		
		
		nums_len = len(nums)

		if nums_len == 0:
			return 0
		else:
			i = 0
			for j in range(1, nums_len):
				if nums[i] != nums[j]:
					i += 1
					nums[i] = nums[j]
		
			return (i + 1)
			
# Runtime: 56 ms, faster than 87.56% of Python3 online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 15.1 MB, less than 5.26% of Python3 online submissions for Remove Duplicates from Sorted Array.

# TC: O(n), n = nums_len
# SC: O(1)