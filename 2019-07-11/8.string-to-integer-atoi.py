class Solution:
    def myAtoi(self, input_str: str) -> int:
        
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -INT_MAX - 1

        str_len = len(input_str)
        start_index = 0

        if str_len == 0:
            return 0

        while start_index < str_len - 1:
            if input_str[start_index] == ' ':
                start_index += 1
            else:
                break

        int_sign = 1
        if input_str[start_index] == '+':
            int_sign = 1
            start_index += 1
        elif input_str[start_index] == '-':
            int_sign = -1
            start_index += 1
        
        int_abs = 0
        int_value = 0
        i = start_index
        while i < str_len:
            if input_str[i].isdigit():
                int_abs = (int_abs * 10) + (ord(input_str[i]) - ord('0'))
                int_value = int_abs * int_sign
                if int_value > INT_MAX:
                    return INT_MAX
                elif int_value < INT_MIN:
                    return INT_MIN
                i += 1
            else:
                break

        return int_value

# Runtime: 44 ms, faster than 61.62% of Python3 online submissions for String to Integer (atoi).
# Memory Usage: 13.2 MB, less than 84.47% of Python3 online submissions for String to Integer (atoi).

# TC: O(n), n = str_len
# SC: O(1)
