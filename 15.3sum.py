class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        triplets = []
        nums_len = len(nums)
        nums.sort()

        for i in range(0, nums_len - 2):
            left_index = i + 1
            right_index = nums_len - 1

            while left_index < right_index:
                sum_test = nums[i] + nums[left_index] + nums[right_index]
                if  sum_test == 0:
                    triplets.append([nums[i], nums[left_index], nums[right_index]])
                    right_index -= 1
                    left_index += 1
                elif sum_test > 0:
                    right_index -= 1
                else:
                    left_index += 1
            
        unique_triplets = set(tuple(triplet) for triplet in triplets)
        return [list(triplet) for triplet in unique_triplets]
            

# Runtime: 2812 ms, faster than 5.00% of Python3 online submissions for 3Sum.
# Memory Usage: 230 MB, less than 5.01% of Python3 online submissions for 3Sum.

# TC: O(n^2), n = nums_len
# SC: O(k), m = triplets