class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_mapping = {
            '2' : ['a', 'b', 'c'],
            '3' : ['d', 'e', 'f'],
            '4' : ['g', 'h', 'i'],
            '5' : ['j', 'k', 'l'],
            '6' : ['m', 'n', 'o'],
            '7' : ['p', 'q', 'r', 's'],
            '8' : ['t', 'u', 'v'],
            '9' : ['w', 'x', 'y', 'z']
        }        

        def combine_next_digits(combination_collect, combination, next_digits):
            if len(next_digits) == 0:
                combination_collect.append(combination)
            else:
                for letter in letter_mapping[next_digits[0]]:
                    combine_next_digits(combination_collect, combination + letter, next_digits[1: ])

        combination_collect = []

        if len(digits) > 0:
            combine_next_digits(combination_collect, '', digits)

        return combination_collect
        
# Runtime: 28 ms, faster than 98.57% of Python3 online submissions for Letter Combinations of a Phone Number.
# Memory Usage: 13.2 MB, less than 34.92% of Python3 online submissions for Letter Combinations of a Phone Number.

# TC: O(n^3 + m^4), n = the amount of 3-letter digits, m = the amount of 4-letter digits
# SC: O(n^3 + m^4), n = the amount of 3-letter digits, m = the amount of 4-letter digits
