class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        nums_len = len(nums)
        closest_value = nums[0] + nums[1] + nums[2]
        
        for i in range(nums_len - 2):
            right_index = nums_len - 1
            left_index = i + 1

            while left_index < right_index:
                value_test = nums[i] + nums[right_index] + nums[left_index]
                if value_test > target:
                    right_index -= 1
                elif value_test < target:
                    left_index += 1
                else:
                    return value_test

                if abs(target - value_test) < abs(target - closest_value):
                    closest_value = value_test

        return closest_value
            
# Runtime: 112 ms, faster than 69.70% of Python3 online submissions for 3Sum Closest.
# Memory Usage: 13.2 MB, less than 47.47% of Python3 online submissions for 3Sum Closest.

# TC: O(n*log2(n) + n*(n/2)!), n = nums_len
# SC: O(1)
