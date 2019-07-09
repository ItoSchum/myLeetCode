class Solution:
    def longestPalindrome(self, s: str) -> str:
        str_len = len(s)
    
        check_table = [[False for col in range(str_len)] for row in range(str_len)]

        max_pali_len = 0
        pali_start_index = 0

        for i in range(str_len - 1, -1, -1):
            for j in range(i, str_len):
                if s[i] == s[j]:
                    if j - i <= 1 or check_table[i + 1][j - 1] == True:
                        check_table[i][j] = True
                        cur_pali_len = j - i + 1
                        if cur_pali_len > max_pali_len:
                            max_pali_len = cur_pali_len
                            pali_start_index = i
        
        pali_end_index = pali_start_index + max_pali_len
        longest_pali = s[pali_start_index : pali_end_index]        
        
        return longest_pali


# Runtime: 3364 ms, faster than 36.49% of Python3 online submissions for Longest Palindromic Substring.
# Memory Usage: 21.7 MB, less than 12.04% of Python3 online submissions for Longest Palindromic Substring.

# TC: O(n), n = str_len
# SC: O(n^2), n = str_len 


