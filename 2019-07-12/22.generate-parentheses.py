class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        result_collect = []
        
        def sub_generate(cur_str = '', left_part_amount = 0, right_part_amount = 0):
            if len(cur_str) == 2 * n:
                result_collect.append(cur_str)
                return
        
            if left_part_amount < n:
                sub_generate(cur_str + '(', left_part_amount + 1, right_part_amount)
        
            if right_part_amount < left_part_amount:
                sub_generate(cur_str + ')', left_part_amount, right_part_amount + 1)

        sub_generate()

        return result_collect


# Runtime: 44 ms, faster than 49.75% of Python3 online submissions for Generate Parentheses.
# Memory Usage: 13.5 MB, less than 26.55% of Python3 online submissions for Generate Parentheses.

# TC: O(4^n / sqrt(n)), n = given n
# SC: O(4^n / sqrt(n))