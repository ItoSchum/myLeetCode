class Solution:
    def maxArea(self, height: List[int]) -> int:
        height_amount = len(height)
        head = 0
        tail = height_amount - 1        

        max_area = 0

        for i in range(height_amount):
            
            width = abs(tail - head)

            if height[head] > height[tail]:
                cur_area = width * height[tail]
                tail -= 1
            else:
                cur_area = width * height[head]
                head += 1
            
            if cur_area > max_area:
                max_area = cur_area

        return max_area


# Runtime: 48 ms, faster than 98.78% of Python3 online submissions for Container With Most Water.
# Memory Usage: 14.5 MB, less than 49.98% of Python3 online submissions for Container With Most Water.

# TC: O(n), n = length of the List 'height'
# SC: O(1)


# e.g.
#   1 2 3 4 5 6
# 1 x ------- o
# 2 x x - o o o
# 3 x x x o | |
# 4 x x x x | |
# 5 x x x x x |
# 6 x x x x x x