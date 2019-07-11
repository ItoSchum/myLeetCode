class Solution:

    def multipleSum(self, nums: List[int], target: int, num_amount: int) -> List[List[int]]:
        if num_amount == 2:    
            combination_of_two_nums = []
            left_index = 0
            right_index = len(nums) - 1
            
            while left_index < right_index:
                value_test = nums[left_index] + nums[right_index]
                
                if value_test > target:
                    right_index -= 1
                elif value_test < target:
                    left_index += 1
                else:
                    combination_of_two_nums.append([nums[left_index], nums[right_index]])
                    left_index += 1
                    right_index -= 1

            return combination_of_two_nums
        
        else:
            combination_collect = []
            nums_len = len(nums)
            for i in range(nums_len):
                for sub_combination in self.multipleSum(nums[i+1: ], target - nums[i], combination_num_amount - 1):
                    if sub_combination:
                        sub_combination.append(nums[i])
                        combination_collect.append(sub_combination)

            unique_combination_collect = set(tuple(sorted(combination)) for combination in combination_collect)
            return [list(combination) for combination in unique_combination_collect]

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        return self.multipleSum(nums, target, 4)

# Runtime: 880 ms, faster than 44.45% of Python3 online submissions for 4Sum.
# Memory Usage: 13 MB, less than 96.75% of Python3 online submissions for 4Sum.

# TC: O(n ^ m), n = len(nums), m = combination_num_amount - 1  --> O(n ^ 3)
# SC: O(n * m), n = len(nums), m = combination_num_amount - 1  --> O(n)

    
                

        
