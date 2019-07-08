class Solution:
	def moveZeroes(self, nums: List[int]) -> None:
		"""
		Do not return anything, modify nums in-place instead.
		"""
		zero_amount = nums.count(0)

		for i in range(zero_amount):
			nums.remove(0)
			nums.append(0)