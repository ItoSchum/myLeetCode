class Solution:
	def longestCommonPrefix(self, strs: List[str]) -> str:
		
		common_prefix = ""
		str_lens = []
		common_prefix_collect = []
		
		for str_item in strs:
			str_lens.append(len(str_item))
		
		if len(strs) == 0:
			return ""
		else:
			min_len = min(str_lens)

		for i in range(min_len):
			cur_char = strs[0][i]
			if all(cur_char == str_item[i] for str_item in strs):
				common_prefix_collect.append(cur_char)
			else:
				break
				
		common_prefix = ''.join(str_item for str_item in common_prefix_collect)

		return common_prefix
			
# Runtime: 36 ms, faster than 83.61% of Python3 online submissions for Longest Common Prefix.
# Memory Usage: 13.3 MB, less than 29.54% of Python3 online submissions for Longest Common Prefix.

# TC: O(n * m), n = the length of the shortest string, m = comparison times
# SC: O(1)