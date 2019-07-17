class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        solution_collect = []
        
        def select_next_char(sub_nums: List[int], temp: List[int]):
            if len(sub_nums) == 1:
                solution_collect.append(temp + sub_nums)
                return
            
            cur_len = len(sub_nums)
            for i in range(cur_len):
                select_next_char(sub_nums[ :i] + sub_nums[i+1: ], temp + [sub_nums[i]])
            
        select_next_char(nums, [])

        return solution_collect

                
# Runtime: 48 ms, faster than 88.33% of Python3 online submissions for Permutations.
# Memory Usage: 13.5 MB, less than 16.56% of Python3 online submissions for Permutations.

# TC: O(n!), n = len(nums)
# SC: O(n!), n = len(nums)

