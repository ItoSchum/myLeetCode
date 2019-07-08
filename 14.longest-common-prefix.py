class Solution:
	def longestCommonPrefix(self, strs: List[str]) -> str:
		
		common_prefix = ""
		str_lens = []
		
		for str_item in strs:
			str_lens.append(len(str_item))
		
		if len(strs) == 0:
			return ""
		else:
			min_len = min(str_lens)

		for i in range(min_len):
			cur_char = strs[0][i]
			if all(cur_char == str_item[i] for str_item in strs):
				common_prefix += cur_char
			else:
				break
				
		return common_prefix
			