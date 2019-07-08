class Solution:
	def removeElement(self, nums: List[int], val: int) -> int:
		
		# nums.sort()
		len_nums = len(nums)
		output_nums = []

		for i in range(len_nums):
			if nums[i] != val:
				output_nums.append(nums[i])

		len_output_nums = len(output_nums)
		
		for i in range(len_output_nums):
			nums[i] = output_nums[i]
		
		return len_output_nums

