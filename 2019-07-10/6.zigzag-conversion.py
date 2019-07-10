class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows == 1:
            return s
        else:
            str_len = len(s)
            transition_num = 2 * (numRows - 1)

            recollect_str = []
            
            for row_index in range(numRows):
                str_index = row_index
                while str_index < str_len:
                    recollect_str.append(s[str_index])
                    # Char in the Bottom row
                    if row_index == numRows - 1:
                        str_index += transition_num
                    # Char in the same Column
                    elif str_index % transition_num == row_index:
                        str_index += transition_num - 2 * row_index
                    # Char in between
                    else:
                        str_index += 2 * row_index
            
        print_str = ''.join(str_item for str_item in recollect_str)
        return print_str

# Runtime: 76 ms, faster than 48.60% of Python3 online submissions for ZigZag Conversion.
# Memory Usage: 13 MB, less than 99.00% of Python3 online submissions for ZigZag Conversion.

# TC: O(n), n = str_len
# SC: O(n), n = str_len


# str_index 

# row = 4 -> row_index = 3
#
#  0        6       12    +6       +6
#  1     5  7    11 13    +4 +2 +4 +2
#  2  4     8 10    14    +2 +4 +2 +4
#  3        9       15    +6       +6

# row = 5
#
#  0           8          16
#  1        7  9       15 17
#  2     6    10    14    18
#  3  5       11 13       19
#  4          12          20