class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_len = len(nums)
        num_map = []
        
        for i in range(nums_len):
            num_map.append(nums[i])

        for i in range(nums_len):
            complement = target - nums[i]
            if complement in num_map and num_map.index(complement) != i:
                return [i, num_map.index(complement)]
        
        return "No such solution"

# Runtime: 780 ms, faster than 36.35% of Python3 online submissions for Two Sum.
# Memory Usage: 13.5 MB, less than 97.58% of Python3 online submissions for Two Sum.

# TC: O(n), n = nums_len
# SC: O(n), n = size of num_map