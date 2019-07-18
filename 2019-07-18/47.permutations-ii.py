class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def select_next_char(sub_nums: List[int], temp: List[int]):
            if len(sub_nums) == 1:
                solution_collect.append(temp + sub_nums)
                return
            
            cur_len = len(sub_nums)
            for i in range(cur_len):
                if i > 0 and sub_nums[i] == sub_nums[i - 1]:
                    continue
                select_next_char(sub_nums[ :i] + sub_nums[i+1: ], temp + [sub_nums[i]])

        solution_collect = []
        nums.sort()
        select_next_char(nums, [])

        return solution_collect

# Runtime: 68 ms, faster than 91.93% of Python3 online submissions for Permutations II.
# Memory Usage: 13.6 MB, less than 17.53% of Python3 online submissions for Permutations II.

# TC: O((n-m)!), n = len(nums), m = duplicate amount
# SC: O((n-m)!), n = len(nums)
