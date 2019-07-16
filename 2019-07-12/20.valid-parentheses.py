class Solution:
    def isValid(self, s: str) -> bool:
        
        str_len = len(s)

        if str_len % 2 != 0:
            return False
        else:
            stack = []
            left_parts = {'(', '[', '{'}
            mapping = {'(': ')', '[': ']', '{': '}'}

            for i in range(str_len):
                if s[i] in left_parts:
                    stack.append(s[i])
                elif stack != [] and s[i] == mapping[stack[-1]]:
                    stack.pop()
                else:
                    return False
            
            if stack == []:
                return True
            else: 
                return False


# Runtime: 36 ms, faster than 74.55% of Python3 online submissions for Valid Parentheses.
# Memory Usage: 13.1 MB, less than 90.28% of Python3 online submissions for Valid Parentheses.

# TC: O(n), n = len(s)
# SC: O(n), n = len(s)