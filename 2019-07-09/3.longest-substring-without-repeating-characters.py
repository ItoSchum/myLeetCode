class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        str_len = len(s)
        start_index = 0
        end_index = 0
        longest_len = 0

        while start_index < str_len and end_index < str_len:
            if s[end_index] not in char_set:
                char_set.add(s[end_index])
                end_index += 1
                longest_len = max(longest_len, end_index - start_index)
            else:
                char_set.remove(s[start_index])
                start_index += 1

        return longest_len

# Runtime: 68 ms, faster than 71.90% of Python3 online submissions for Longest Substring Without Repeating Characters.
# Memory Usage: 13.4 MB, less than 23.78% of Python3 online submissions for Longest Substring Without Repeating Characters.

# TC: O(n), n = len(s)
# SC: O(min(m, n) + k), m = char_set, n = s, k = slide_window
