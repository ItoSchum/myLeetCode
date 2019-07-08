class Solution:
	def removeDuplicates(self, nums: List[int]) -> int:
		
		nums.sort()
		unique_nums = []
		
		len_nums = len(nums)
		if len_nums == 0:
			return 0

		for i in range(len_nums):
			if nums[i] not in unique_nums:
				unique_nums.append(nums[i])
		
		unique_nums.sort()
		len_unique_nums = len(unique_nums)
		
		for i in range(len_unique_nums):
			nums[i] = unique_nums[i]
		
		return len_unique_nums
			
