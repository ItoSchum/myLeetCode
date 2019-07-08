class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
    	list_len = len(nums)
    	for i in range(0, list_len - 1):
    		for j in range(i + 1, list_len):
    			if target == nums[i] + nums[j]:
    				return [i, j]